from flask import Flask, render_template

# Create a new Flask application
app = Flask(__name__)

# Define a route to render an HTML file
@app.route('/')
def home():
    return render_template('index.html')

# Run the app when this script is executed
if __name__ == '__main__':
    app.run()
