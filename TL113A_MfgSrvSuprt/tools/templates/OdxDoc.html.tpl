<html>
	<head>
		<style type="text/css">${css}</style>
		<link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.4.0/css/font-awesome.min.css" rel="stylesheet" integrity="sha256-k2/8zcNbxVIh5mnQ52A0r3a6jAgMGxFJFE2707UxGCk= sha512-ZV9KawG2Legkwp3nAlxLIVFudTauWuBpC10uEafMHYL0Sarrz5A7G79kXh5+5+woxQ5HM559XX2UZjMJ36Wplg==" crossorigin="anonymous">
		<script type="text/javascript">
			var app = {};
			app.bootstrap = ${pages.toJSON()};
		</script>
		<title>${program} ${revision} Manufacturing Service Reference</title>
		<style type="text/css">
			pre {
				overflow-x: auto;
			}
			pre code {
				overflow-wrap: normal;
				white-space: pre;
			}
			.row {
				margin-top: 10px;
			}
			.bg-highlight {
				background-color: #FF0;
			}
			#content {
				overflow-y: scroll;
				height: 98%;
			}
		</style>
		<script type="text/x-handlebars-template" id="page-list-template">
			{{#each pages}}
				{{> page}}
			{{/each}}
		</script>
		<script type="text/x-handlebars-template" id="page-template">
			<h1 id="{{link}}">{{title}}</h1>
			{{{html}}}
			{{#each services}}
				{{~> service}}
			{{/each}}
			{{#each sections}}
				{{> section}}
			{{/each}}
		</script>
		<script type="text/x-handlebars-template" id="section-template">
			<h2 id="{{link}}">{{heading}}</h2>
			{{{html}}}
			{{#each services}}
				{{~> service}}
			{{/each}}
		</script>
		<script type="text/x-handlebars-template" id="service-template">
			<h3 id="{{short}}">{{long}}</h3>
			{{{desc}}}
			<h4>Access</h4>
			<table class="table table-striped table-condensed">
				<tr>
					<th>Condition</th>
					<th>Required</th>
				</tr>
				<tr>
					<td>Nxtr Session</td>
					<td>{{ternary access.nexteerSession 'Yes' 'No'}}</td>
				</tr>
				<tr>
					<td>Security Access</td>
					<td>{{ternary access.securityAccess 'Yes' 'No'}}</td>
				</tr>
			</table>
			<h4>Request: ({{reqLen}})</h4>
			<pre class="service-diagram"><code>{{request}}</code></pre>
			<h4>Response: ({{respLen}})</h4>
			<pre class="service-diagram"><code>{{response}}</code></pre>
			<h4>Unique Negative Response Codes</h4>
			<ul>
				{{#each nrcs}}
					{{#if this}}
						<li>{{this}}</li>
					{{else}}
						<li>
							<em>None</em>
						</li>
					{{/if}}
				{{/each}}
			</ul>
		</script>
		<script type="text/x-handlebars-template" id="nav-template">
			{{#each items}}
				<li>
					<a href="#{{link}}" data-target="#{{id}}">
						{{title}}
					</a>
				</li>
			{{/each}}
		</script>
		<script type="text/x-handlebars-template" id="not-found-template">
			<h1>
				Eek! 404:
				<small>Page Not Found</small>
			</h1>
			<p>The page you have requested simply isn't here.  Make a U-turn and try a different road.</p>
		</script>
	</head>
	<body>
		<div class="container-fluid">
			<div class="row">
				<div class="col-md-2">
					<div class="row">
						<div class="col-md-12">
							<strong style="font-size:110%">Manufacturing Services Reference</strong>
							<strong>Program:</strong> ${program} <br/>
							<strong>Version:</strong> ${revision}
						</div>
					</div>
					<div class="row">
						<div class="col-md-12">
							<button class="btn btn-default btn-block" type="button" id="back">
								<i class="fa fa-arrow-left"></i>
								Back
							</button>
						</div>
					</div>
					<div class="row">
						<div class="col-md-12" id="nav-pane">
							<ul class="nav nav-pills nav-stacked" id="navigation"></ul>
						</div>
					</div>
					<div class="row">
						<div class="col-md-12">
							<form method="get" action="" id="search">
								<div class="input-group">
									<input type="text" class="form-control" placeholder="Search" id="q">
									<span class="input-group-btn">
										<button class="btn btn-default" type="submit">Go</button>
									</span>
								</div>
							</form>
						</div>
					</div>
					<div class="row">
						<div class="col-md-12">
							<p class="text-muted">
								Generated on ${timestamp}
								using ${tool}
								version ${version}.
							</p>
						</div>
					</div>
				</div>
				<div class="col-md-10" id="content" data-spy="scroll" data-target="#nav-pane">
					<i class"fa fa-refresh fa-spin"></i>Loading...
				</div>
			</div>
		</div>
	</body>
	<script type="text/javascript">${js}</script>
</html>