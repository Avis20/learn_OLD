from flask import Flask, Response, request
import requests
import hashlib

app = Flask(__name__)

default_name = 'Avisss'
salt = 'SALT'

@app.route('/', methods=['GET', 'POST'])
def main():
    name = default_name

    if request.method == 'POST':
        name = request.form['name']

    saled = salt + name
    hashsum = hashlib.sha256(saled.encode()).hexdigest()

    header = '<!DOCTYPE html> <html lang="en"> <head> <meta charset="UTF-8"> <title>Identidock</title> </head><body>'
    body = '''
    <form method="POST" action="/">
        Hello <input type="text" name="name" value="{}"/>
        <input type="submit" value="submit"/>
    </form>
    <p>You look like a: <img src="/monster/{}"/></p>
    '''.format(name, hashsum)
    footer = '</body></html>'

    return header + body + footer

@app.route('/monster/<name>')
def get_identicon(name):
    # return "Hello, World!\n"
    req = requests.get('http://dnmonster:8080/monster/' + name + '?size=80')
    image = req.content
    return Response(image, mimetype='image/png')

# def hello_world():
#     return "Hello, World!\n"

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')