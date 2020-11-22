from abc import ABC, abstractmethod
import os

cmake_lists_fn = "CMakeLists.txt"
solution_fn = "{}_solution.h"
test_fn = "{}_test.cpp"
project_root = os.path.dirname(__file__)

cmake_list_template = """\
add_executable({}_test {}_test.cpp)
target_link_libraries({}_test GTest::GTest glog)"""


test_template = """\
#include <glog/logging.h>
#include "gtest/gtest.h"

#include "{}_{}/{}_solution.h"

using namespace lst::leet;

TEST({}Test, LeetTest) {{
    Solution s;
}}

int main(int argc, char **argv) {{
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}}
"""

solution_template = """\
#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
};
}  // namespace leet
}  // namespace lst
"""

class FileWriter(ABC):
    def __init__(self, question_id, name):
        self.question_id_ = question_id
        self.name_ = name

    @abstractmethod
    def get_file_name(self):
        pass

    @abstractmethod
    def get_file_content(self):
        pass

    @abstractmethod
    def get_dir(self):
        pass

    def write_file(self):

        dir_name = self.get_dir()
        if not os.path.exists(dir_name):
            os.mkdir(dir_name)

        fn = os.path.join(dir_name, self.get_file_name())
        content = self.get_file_content()
        if os.path.exists(fn):
            print("{} exists!".format(fn))

        with open(fn, 'w') as fd:
            fd.write(content)

        print(fn)

    def get_solution_dir(self):
        return os.path.join(project_root, "include", "{}_{}".format(self.question_id_, self.name_))

    def get_test_dir(self):
        return os.path.join(project_root, "test", "{}_{}".format(self.question_id_, self.name_))


class CMakeFileWriter(FileWriter):

    def __init__(self, question_id, name):
        super().__init__(question_id, name)

    def get_file_name(self):
        return cmake_lists_fn

    def get_file_content(self):
        return cmake_list_template.format(self.name_, self.name_, self.name_)

    def get_dir(self):
        return self.get_test_dir()


class TestWriter(FileWriter):


    def __init__(self, question_id, name, upper_name):
        super().__init__(question_id, name)
        self.upper_name_ = upper_name

    def get_file_name(self):
        return test_fn.format(self.name_)

    def get_file_content(self):
        return test_template.format(self.question_id_, self.name_, self.name_, self.upper_name_)

    def get_dir(self):
        return self.get_test_dir()


class SolutionWriter(FileWriter):


    def __init__(self, question_id, name):
        super().__init__(question_id, name)

    def get_file_name(self):
        return solution_fn.format(self.name_)

    def get_file_content(self):
        return solution_template

    def get_dir(self):
        return self.get_solution_dir()


def main():
    question_id = "9"
    question_name = ["Palindrome", "Number"]
    lower_name = "_".join(question_name).lower()
    upper_name = "".join(question_name)

    solution_writer = SolutionWriter(question_id, lower_name)
    cmake_writer = CMakeFileWriter(question_id, lower_name)
    test_writer = TestWriter(question_id, lower_name, upper_name)
    for writer in [cmake_writer, solution_writer, test_writer]:
        writer.write_file()


if __name__ == '__main__':
    main()