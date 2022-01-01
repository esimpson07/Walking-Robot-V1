from telnetlib import Telnet
cats = 4040

with Telnet('192.168.1.1',23) as tn:
    tn.interact()
    while True:
        cats = int(input())
        print(cats)
        tn.write(cats)


