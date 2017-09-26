import mechanize
import re

cj = mechanize.CookieJar()
br = mechanize.Browser()
br.set_cookiejar(cj)

br.open('http://www.hacker.org/forum/login.php')
br.select_form(nr=0)
br.form['username'] = ''
br.form['password'] = ''
br.submit()

br.open('http://www.hacker.org/challenge/chal.php?id=76')
chal = str(br.response().read())
ans = re.match(r".*<b>(.*)</b>.*", chal, re.DOTALL)
print (ans.group(1))

br.select_form(nr=1)
br.form['answer'] = ans.group(1)
br.submit()

if "is correct" in str(br.response().read()):
    print "Success!"
else:
    print "Failed!"
