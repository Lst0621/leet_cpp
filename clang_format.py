import os
import tqdm


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
    for file_name in tqdm.tqdm(files_to_format):
        cmd = "clang-format --style=file -i {}".format(file_name)
        os.system(cmd)

    print("Formatting done:")

    for file_name in files_to_format:
        print("Formatting: {}".format(file_name))


if __name__ == '__main__':
    main()
