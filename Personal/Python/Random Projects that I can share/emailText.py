import smtplib
from email.mime.text import MIMEText
from email.mime.image import MIMEImage
from email.mime.multipart import MIMEMultipart
import time

#Texts a number an image of maurice a number of times through the smtp gateway

email = "theHolyMaurice@gmail.com"
pas = "Peepee123"

#Blocked out number for privacy
#sms_gateway = '###########@pm.sprint.com'
sms_gateway = '###########@vtext.com'
# The server we use to send emails in our case it will be gmail but every email provider has a different smtp # and port is also provided by the email provider.
smtp = "smtp.gmail.com"
port = 587
server = smtplib.SMTP(smtp,port)
server.starttls()
server.login(email,pas)

msg = MIMEMultipart()
msg['From'] = email
msg['To'] = sms_gateway
#msg['Subject'] = 'Hello'
#body = ''
#msg.attach(MIMEText(body, 'plain'))
fp = open('/Users/dhruvnanavati/Desktop/RandomCS/IMG_9628.PNG', 'rb' )
msg_img = MIMEImage( fp.read() )
fp.close()
msg.attach(msg_img)


# Make sure you add a new line in the subject msg['Subject'] = "You can insert anything\n"
# Make sure you also add new lines to your body body = "You can insert message here\n"
# and then attach that body furthermore you can also send html content. msg.attach(MIMEText(body, 'plain'))

sms = msg.as_string()

for x in range(3):
    time.sleep(1)
    server.sendmail(email,sms_gateway,sms)

server.quit()
