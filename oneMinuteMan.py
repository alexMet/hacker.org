import urllib.request
from datetime import *
from bs4 import BeautifulSoup
import sched, time

'''
06:52:24.086902
<html><body>
i declare the answer is gugglemuggle
'''

timer = sched.scheduler(time.time, time.sleep)

def check_site():
    url = "http://www.hacker.org/challenge/misc/minuteman.php"
    fp = urllib.request.urlopen(url)
    html = fp.read().decode("utf8")
    fp.close()
    
    print (str(datetime.time(datetime.now())))
    print (html, "\n")

    if html == "<html><body>\nback later":
        timer.enter(60, 1, check_site)

if __name__ == "__main__":
    timer.enter(60, 1, check_site)
    timer.run()
