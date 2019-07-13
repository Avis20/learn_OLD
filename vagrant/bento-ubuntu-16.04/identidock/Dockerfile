from python:3.7

run groupadd -r uwsgi && useradd -r -g uwsgi uwsgi

run pip install Flask==0.10.1 uWSGI==2.0.17.1
workdir /app
copy app /app

expose 9090 9191
user uwsgi

cmd ["uwsgi", "--http", "0.0.0.0:9090", "--wsgi-file", "/app/identidock.py", "--callable", "app", "--stats", "0.0.0.0:9191"]

# cmd ["python", "identidock.py"]