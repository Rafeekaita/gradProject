#download the newly released yolov4-tiny weights
%cd /content/darknet
!wget https://github.com/AlexeyAB/darknet/releases/download/darknet_yolo_v4_pre/yolov4-tiny.weights
!wget https://github.com/AlexeyAB/darknet/releases/download/darknet_yolo_v4_pre/yolov4-tiny.conv.29

#if you already have YOLO darknet format, you can skip this step
#otherwise we recommend formatting in Roboflow
%cd /content/darknet
!curl -L "https://app.roboflow.com/ds/PBfyfGNCTb?key=nBd4MNvtM6" > roboflow.zip; unzip roboflow.zip; rm roboflow.zip
#Set up training file directories for custom dataset
%cd /content/darknet/
%cp train/_darknet.labels data/obj.names
%mkdir data/obj
#copy image and labels
%cp train/*.jpg data/obj/
%cp valid/*.jpg data/obj/

%cp train/*.txt data/obj/
%cp valid/*.txt data/obj/

with open('data/obj.data', 'w') as out:
  out.write('classes = 3\n')
  out.write('train = data/train.txt\n')
  out.write('valid = data/valid.txt\n')
  out.write('names = data/obj.names\n')
  out.write('backup = backup/')

#write train file (just the image list)
import os

with open('data/train.txt', 'w') as out:
  for img in [f for f in os.listdir('train') if f.endswith('jpg')]:
    out.write('data/obj/' + img + '\n')

#write the valid file (just the image list)
import os

with open('data/valid.txt', 'w') as out:
  for img in [f for f in os.listdir('valid') if f.endswith('jpg')]:
    out.write('data/obj/' + img + '\n')
#we build config dynamically based on number of classes
#we build iteratively from base config files. This is the same file shape as cfg/yolo-obj.cfg
def file_len(fname):
  with open(fname) as f:
    for i, l in enumerate(f):
      pass
  return i + 1

num_classes = file_len('train/_darknet.labels')
max_batches = num_classes*2000
steps1 = .8 * max_batches
steps2 = .9 * max_batches
steps_str = str(steps1)+','+str(steps2)
num_filters = (num_classes + 5) * 3


print("writing config for a custom YOLOv4 detector detecting number of classes: " + str(num_classes))

#Instructions from the darknet repo
#change line max_batches to (classes*2000 but not less than number of training images, and not less than 6000), f.e. max_batches=6000 if you train for 3 classes
#change line steps to 80% and 90% of max_batches, f.e. steps=4800,5400
if os.path.exists('./cfg/custom-yolov4-tiny-detector.cfg'): os.remove('./cfg/custom-yolov4-tiny-detector.cfg')


#customize iPython writefile so we can write variables
from IPython.core.magic import register_line_cell_magic

@register_line_cell_magic
def writetemplate(line, cell):
    with open(line, 'w') as f:
        f.write(cell.format(**globals()))
# Open the data/obj.names file and read the names of the classes
with open("data/obj.names", "r") as f:
    names = f.read().splitlines()

# Print the number of names and the names
print(f"Number of names: {len(names)}")
print(f"Names: {names}")

# If the number of names is not equal to 80, you need to add or remove some names
# For example, if you only have 2 classes, you can remove the rest of the names
if len(names) != 80:
    # Keep only the first 2 names
    names = names[:2]

    # Write the new names to the data/obj.names file
    with open("data/obj.names", "w") as f:
        for name in names:
            f.write(name + "\n")

    # Print the updated number of names and the names
    print(f"Updated number of names: {len(names)}")
    print(f"Updated names: {names}")

# Open the data/obj.data file and read the parameters
with open("data/obj.data", "r") as f:
    params = f.read().splitlines()

# Print the parameters
print(f"Parameters: {params}")

# If the names parameter is not pointing to data/obj.names, you need to change it
# For example, if it is pointing to data/coco.names, you can replace it with data/obj.names
for i, param in enumerate(params):
    # Split the parameter by "=" sign
    key, value = param.split("=")

    # If the key is "names", check the value
    if key == "names":
        # If the value is not data/obj.names, replace it with data/obj.names
        if value != "data/obj.names":
            # Update the value
            value = "data/obj.names"

            # Write the new value to the data/obj.data file
            with open("data/obj.data", "w") as f:
                for j, p in enumerate(params):
                    # If it is the same index as the names parameter, use the updated value
                    if j == i:
                        f.write(key + "=" + value + "\n")
                    # Otherwise, use the original parameter
                    else:
                        f.write(p + "\n")

            # Print the updated parameter
            print(f"Updated parameter: {key}={value}")
#If you get CUDA out of memory adjust subdivisions above!
#adjust max batches down for shorter training above
!./darknet detector train data/obj.data cfg/yolov4-tiny-custom.cfg yolov4-tiny.conv.29 -dont_show -map
