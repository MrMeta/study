# -*- coding: utf-8 -*-

import random

from flask import Flask, session, render_template, request, flash


app = Flask(__name__)
app.secret_key = 'A0Zr98j/3yX R~XHH!jmN]LWX/,?RT'


@app.route('/')
def index():
    return render_template('index.html', title=u'숫자야구 : 인덱스')


@app.route('/answer', methods=['GET','POST'])
def answer():
    if not session.get('answer'):
        session['answer'] = ''.join(map(str,random.sample(range(0,10),4)))
        session['chance'] = 10
        session['log'] = ''
        flash(u'새 문제가 출제되었습니다.')
    else:
        if 'answer' in request.form.keys():
            input = list(request.form['answer'])
            ans = list(session['answer'])
            if session['chance'] > 1:
                if input == ans:
                    flash(u'4 strike. 정답은 ' + request.form['answer'] + u'입니다.')
                    session['answer'] = None
                    return render_template('alert.html', title=u'숫자야구 : 정답')
                elif len(input) != 4:
                    flash(u'4자리 숫자로만 시도해주세요.')
                else:
                    session['chance'] -= 1
                    
                    strike = ball = 0
                    for i, c in enumerate(input):
                        if c == ans[i]:
                            strike += 1
                        elif c in ans:
                            ball += 1

                    log = session['log'].split('|')
                    for x in log:
                        flash(x)

                    flash(u'%s - %d strike, %d ball, 기회가 %d번 남았습니다.' % (request.form['answer'], strike, ball, session['chance']))

                    log.append(u'%s - %d strike, %d ball' % (request.form['answer'], strike, ball))
                    session['log'] = '|'.join(log)
            else:
                flash(u'기회를 모두 소진하셨습니다. 정답은 ' + request.form['answer'] + u'입니다.')
                session['answer'] = None
                return render_template('alert.html', title=u'숫자야구 : 패배')
        else:
            flash(u'값을 입력해주세요.')
    return render_template('answer.html', title=u'숫자야구 : 도전')