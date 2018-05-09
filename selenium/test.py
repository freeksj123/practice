#! /usr/bin/python

import time

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains

#url = "http://portal.hnu.edu.cn/portal.do"
url = "https://pt.hnu.edu.cn/zfca?yhlx=teacher&login=0122579031373493685&url=login.aspx"
myname = "user101"
mypass = [ 'a', 'b', 'c', 'd', '1', '2', '3', '4', '5', '6', '7' ]

#browser = webdriver.Firefox()
browser = webdriver.Chrome()
browser.get(url)

#actions = ActionChains(browser)

#actions.reset_actions()

username = browser.find_element_by_id("username")

username.click()

username.send_keys(myname)

#actions.send_keys_to_element(username, myname + Keys.TAB).perform()

#actions.reset_actions()

#time.sleep(5)


password = browser.find_element_by_id("password")

password.click()

for c in mypass:
        password.send_keys(c)
            #time.sleep(1)

            login = browser.find_element_by_name("submit1")

            login.click()

            #jwxt = browser.find_element_by_id("135496455412324070")

            #jwxt.click()

            chengjiguanli = browser.find_element_by_id("memuBarText2")

            chengjiguanli.click()



            #print("\nQuit browser\n")
            #browser.quit()


