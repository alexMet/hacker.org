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

br.open('http://www.hacker.org/challenge/chal.php?id=78')
chal = str(br.response().read())
sen = re.match(r".*<b>(.*)</b>", chal, re.DOTALL).group(1)
beg = "".join(re.findall(r"([^<]*)<span[^<]*</span>", sen, re.DOTALL))
end = re.findall(r".*</span>(.*)", sen, re.DOTALL)[0]
ans = beg + end
print (ans)

br.select_form(nr=1)
br.form['answer'] = ans
br.submit()

if "is correct" in str(br.response().read()):
    print "Success!"
else:
    print "Failed!"
