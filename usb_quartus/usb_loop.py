import usb.control
import time
import numpy as np
from PIL import Image
#filename = 'test.jpg'

dev = usb.core.find(idVendor=0x04CC, idProduct=0x1A62)
dev.set_configuration()
cfg = dev.get_active_configuration()
intf = cfg[(0, 0)]
CHUNK_SIZE = 64

# Open the JPEG image file using the Pillow library
image = Image.open('C:/Users/dhaua/Desktop/usb_quartus/cat2.jpg')

# Convert the image to RGB format
image = image.convert('RGB')

count_packet = 0
# Get the image dimensions
width, height = image.size
data1 = []
nu = 0
# Send the image data in packets of 64 bytes
for y in range(height):
    for x in range(0, width, 1):
        r, g, b = image.getpixel((x, y))
        r = np.uint8(r)
        g = np.uint8(g)
        b = np.uint8(b)
        nu = np.uint8(nu)
        data = [r, g, b, nu]
        data = np.array(data, dtype = np.uint8)
       # print(data)
        #print(data.tobytes())
       # data = bytes([r, g, b, 0])
        #print(data)
        #data = [r, g, b, 0]
       # print(bytes(data))
#        if(len(data1) == 0):
 #          data1.insert(0,data)
  #      else:
        data1.insert((len(data1)) ,data)
        if(len(data1) == 64):
           # print(data1)
            data1 = np.array(data1, dtype = np.uint8)
          #  print(data1.tobytes())
          #  print(len(data1))
            dev.write(0x1, data1.tobytes(), timeout=5000)
       #     print("packet sent")
           # data1 = []
            #print(bytes(data1))
            data1 = []
            count_packet += 1
            #time.sleep(2)
print(count_packet)
        # Send the data in chunks of CHUNK_SIZE bytes
#        for i in range(0, len(data), CHUNK_SIZE):
 #           chunk = data[i:i+CHUNK_SIZE]
  #          dev.write(0x1, chunk, timeout=5000)
   #         print(chunk)
            #array = np.random.randint(255, size=64, dtype=np.uint8)
#array_end = np.empty(0, dtype=np.uint8)


#real = dev.write(0x1, array.tobytes(), 2000)
#print("out = ", real)
#time.sleep(0.1)

#real_in = dev.read(0x82, len(array), 200)
#print("len = ", len(real_in))
#print("in = ", real_in)


