import os
from multiprocessing.pool import Pool


def get_suffix_to_format():
    return ['h', 'cpp']


def get_folder_to_format():
    return ["include", "src", "test"]


def main():
    all_files = []
    folders = get_folder_to_format()
    for folder in folders:
        for (dir_path, _, filenames) in os.walk(folder):
            for file_name in filenames:
                all_files.append(os.path.join(dir_path, file_name))

    suffix_list = get_suffix_to_format()

    def check_file_suffix(fn):
        for suffix in suffix_list:
            if fn.endswith(suffix):
                return True
        return False

    files_to_format = list(filter(check_file_suffix, all_files))

    num_process = 6
    with Pool(num_process) as p:
        p.map(format_file, files_to_format)

    print("done!")


def format_file(file_name):
    print("Formatting {}: {}".format(os.getpid(), file_name))
    cmd = "clang-format --style=file -i {}".format(file_name)
    os.system(cmd)


if __name__ == '__main__':
    main()
