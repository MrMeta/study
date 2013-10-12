# -*- coding: utf-8 -*-

from gevent.wsgi import WSGIServer
from index import app
import os

HOST = '0.0.0.0'
PORT = 15151

http_server = WSGIServer((HOST, PORT), app)
http_server.serve_forever()