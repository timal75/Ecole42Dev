from flask import Flask

app = Flask(__name__)

@app.route('/')
def index():
	return '<html> \
				<head> \
					<style type="text/css"> \
						body {background: black;color: white;} \
						div.container {	max-width:500px; \
										margin: 100px auto; \
										border: 20px solid white; \
										padding: 10px; \
										text-align: center;} \
						h4 {text-transform: uppercase;} \
					</style> \
				</head> \
				<body> \
					<div class="container"> \
						<h1>Hello World </h1> \
					</div> \
				</body> \
			</html>' 

if __name__ == "__main__":
	app.run(host="0.0.0.0", port=3000)

