import os.path
import time


def create_new_file(path, name, file_type):
    file_path = path + name + file_type
    if os.path.exists(file_path):
        raise Exception("file already exists in " + file_path)
    else:
        if file_type == '.h':
            with open(file_path, 'w') as file:
                file.write("#ifndef " + name.upper() + "_H" + "_INCLUDED\n")
                file.write("#define " + name.upper() + "_H" + "_INCLUDED\n\n\n")
                file.write("#endif")
        elif file_type == '.cpp':
            with open(file_path, 'w') as file:
                file.write("#include <%s.h>" % name)

        print("file created successfully: " + name + file_path)


i = input("file name: ")
create_new_file("include/", i, ".h")
create_new_file("src/", i, ".cpp")

time.sleep(3)