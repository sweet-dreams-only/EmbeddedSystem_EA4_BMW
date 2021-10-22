var app = app || {};

(function () {
	'use strict';

	var pages = app.bootstrap;

	var services = [];
	_.each(pages, function(page) {
		_.each(page.services, function(service) {
			services.push(service);
		});
		_.each(page.sections, function(section) {
			_.each(section.services, function(service) {
				services.push(service);
			});
		});
	});

	var options = {
		preventIndent: true
	};

	var templates = {};
	templates.nav = Handlebars.compile($('#nav-template').html(), options);
	templates.pages = Handlebars.compile($('#page-list-template').html(), options);
	templates.page = Handlebars.compile($('#page-template').html(), options);
	templates.section = Handlebars.compile($('#section-template').html(), options);
	templates.service = Handlebars.compile($('#service-template').html(), options);
	templates.e404 = Handlebars.compile($('#not-found-template').html(), options);

	Handlebars.registerPartial("page", templates.page);
	Handlebars.registerPartial("section", templates.section);
	Handlebars.registerPartial("service", templates.service);

	Handlebars.registerHelper('ternary', function(test, yes, no) {
		return test ? yes : no;
	});

	$('#back').click(function(event) {
		window.history.back();
	}).hide();

	$('#search').submit(function(event) {
		event.preventDefault();
		var query = $('#q').val();
		window.location.href = '#search?q=' + encodeURIComponent(query);
	});

	var render = function(html) {
		$('#content').html(html);
		// This works around the fact that tables don't have any styling by default in Bootstrap.
		$('table').addClass('table');
	};

	var PageRouter = Backbone.Router.extend({
		routes: {
			'': 'root',
			'page/:title': 'page',
			'page/:title/section/:heading': 'section',
			'page/:title/section/:heading/service/:short': 'section_service',
			'page/:title/service/:short': 'service',
			'search?q=:text': 'search',
			'*notFound': 'not_found'
		},
		root: function(title) {
			// Display all services
			render(templates.pages({pages: pages}));

			// Show pages in navigation
			var items = [];
			_.each(pages, function(page) {
				items.push({
					'title': page.title,
					'id': page.link,
					'link': 'page/' + page.link,
				});
			});
			$('#navigation').html(templates.nav({items: items}));
			$('#back').hide();
		},
		page: function(title) {
			// Filter services to only those on this page
			var page = _.find(pages, function(page) {
				return page.link == title;
			});
			render(templates.page(page));

			// Show sections (if available) or services in navigation
			var items = [];
			if (page.sections.length > 0) {
				_.each(page.sections, function(section) {
					items.push({
						'title': section.heading,
						'id': section.link,
						'link': 'page/' + title + '/section/' + section.link,
					});
				});
			} else {
				_.each(page.services, function(service) {
					items.push({
						'title': service.long,
						'id': service.short,
						'link': 'page/' + title + '/service/' + service.short,
					});
				});
			}
			$('#navigation').html(templates.nav({items: items}));
			$('#back').show();
		},
		section: function(title, heading) {
			// Filter services to only those in this section
			var page = _.find(pages, function(page) {
				return page.link == title;
			});
			var section = _.find(page.sections, function(section) {
				return section.link == heading;
			});
			render(templates.section(section));

			// Show list of services in navigation pane
			var items = _.map(section.services, function(service) {
				return {
					'title': service.long,
					'id': service.short,
					'link': 'page/' + title + '/section/' + heading + '/service/' + service.short,
				};
			});
			$('#navigation').html(templates.nav({items: items}));
			$('#back').show();
		},
		section_service: function(title, heading, short) {
			var page = _.find(pages, function(page) {
				return page.link == title;
			});
			var section = _.find(page.sections, function(section) {
				return section.link == heading;
			});
			var service = _.find(section.services, function(service) {
				return service.short == short;
			});
			render(templates.service(service));
			$('#back').show();
		},
		service: function(title, short) {
			var page = _.find(pages, function(page) {
				return page.link == title;
			});
			var service = _.find(page.services, function(service) {
				return service.short == short;
			});
			render(templates.service(service));
		},
		search: function(text) {
			var index = lunr(function () {
				this.ref('short')
				this.field('long', {boost: 10})
				this.field('desc')
				this.field('request')
				this.field('response')
				this.field('nrcs')
			});
			_.each(services, function(service) {
				index.add(service);
			});
			var results = _.map(index.search(text), function(result) {
				return _.find(services, function(service) {
					return service.short == result.ref;
				});
			});
			var context = {
				heading: 'Search Results: "' + text + '"',
				services: results
			};
			var html = templates.section(context);
			html = highlight(html, text);
			render(html);
		},
		not_found: function() {
			render(templates.e404());
			$('#navigation').html('');
			$('#back').show();
		}
	});

	function escapeRegExp(str) {
		return str.replace(/([.*+?^=!:${}()|\[\]\/\\])/g, "\\$1");
	}

	function highlight(str, phrase) {
		var replace = '<span class="bg-highlight">' + phrase + '</span>';
		return str.replace(new RegExp(escapeRegExp(phrase), 'gi'), replace);
	}

	app.PageRouter = new PageRouter();
	Backbone.history.start();
})();