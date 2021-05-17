from smbus import SMBus

addr = 0x8 #bus address
bus = SMBus(1) # indicate /dev/ic2 - 1

num = 1

print("Enter 1 (ON) or 0 (OFF): ")
while num == 1:
	ledState = input(">>>   ")
	if (ledState == "1"):
		bus.write_byte(addr, 0x1) #switch on
	elif (ledState == "0"):
		bus.write_byte(addr, 0x0) #switch off
	else:
		num = 0
