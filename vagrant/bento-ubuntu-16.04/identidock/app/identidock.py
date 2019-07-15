from flask import Flask
app = Flask(__name__)

default_name = 'Avis'

@app.route('/')
def get_identicon():
    name = default_name
    header = '<!DOCTYPE html> <html lang="en"> <head> <meta charset="UTF-8"> <title>Identidock</title> </head><body>'
    body = '''
    <from method="POST">
        Hello <input type="text" name="name" value="{}"/>
        <input type="submit" value="submit"/>
    </from>
    <p>You look like a: <img src="/monster/monstrer.png"/></p>
    '''.format(name)
    footer = '</body></html>'

    return header + body + footer

# def hello_world():
#     return "Hello, World!\n"

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')