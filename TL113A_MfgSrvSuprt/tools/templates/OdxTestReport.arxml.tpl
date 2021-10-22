<html>
	<head>
		<style type="text/css">${css}</style>
		<title>Test Report - ${'Pass' if failures == 0 else 'Failed'}</title>
		<script type="text/javascript">${js}</script>
	</head>
	<body>
		<div class="container">
			<h1>Common Manufacturing Services Test Report</h1>
			<div class="row">
				<div class="col-md-4">
					<div class="panel panel-default">
						<div class="panel-heading">
							<h3 class="panel-title">Details</h3>
						</div>
						<table class="table">
							<tr>
								<td>Program:</td>
								<td>${program}</td>
							</tr>
							<tr>
								<td>Software Version:</td>
								<td>${revision}</td>
							</tr>
							<tr>
								<td>Generation Tool:</td>
								<td>${tool}</td>
							</tr>
							<tr>
								<td>Tool Version:</td>
								<td>${version}</td>
							</tr>
							<tr>
								<td>Generation Time:</td>
								<td>${timestamp}</td>
							</tr>
							<tr>
								<td>Total Tests:</td>
								<td>${len(reports)}</td>
							</tr>
							<tr>
								<td>Failures:</td>
								<td>${failures}</td>
							</tr>
						</table>
					</div>
					<canvas id="pie-chart" style="width:100%; height:auto;"></canvas>
				</div>
				<div class="col-md-8">
					<div class="list-group">
						% for report in reports:
							<a href="#${report.uuid}" class="list-group-item">
								<span class="label ${'label-success' if report.passed else 'label-danger'} pull-right">
									${'Pass' if report.passed else 'Fail'}
								</span>
								${report.test.title()}
							</a>
						% endfor;
					</div>
				</div>
			</div>
			<h1>Report Details</h1>
			% for report in reports:
				<h2 id="${report.uuid}">
					${report.test.title()}
					<span class="label ${'label-success' if report.passed else 'label-danger'} pull-right">
						${'Pass' if report.passed else 'Fail'}
					</span>
				</21>
				<table class="table table-striped table-condensed">
					<thead>
						<tr>
							<th>Description</th>
							<th>Result</th>
							<th>Comment</th>
						</tr>
					</thead>
					<tbody>
						% for step in report.steps:
							<tr class="${'danger' if step.status == 'Failed' else ''}">
								<td>${step.title}</td>
								<td>
									% if step.status == 'Pending':
										<span class="text-warning">[Pending]</span>
									% elif step.status == 'Failed':
										<span class="text-danger">[Fail]</span>
									% else:
										<span class="text-success">[Pass]</span>
									% endif;
								</td>
								<td>${step.reason}</td>
							</tr>
						% endfor;
					</tbody>
				</table>
			% endfor;
		</div>
		<script type="text/javascript">
			var ctx = document.getElementById("pie-chart").getContext("2d");
			var data = [
				{
					value: ${passes},
					color:"#5cb85c",
					highlight: "#71c171",
					label: "Pass"
				},
				{
					value: ${failures},
					color:"#d9534f",
					highlight: "#df706c",
					label: "Fail"
				},
			];
			var myPieChart = new Chart(ctx).Pie(data);
		</script>
	</body>
</html>