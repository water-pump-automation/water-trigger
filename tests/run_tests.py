from subprocess import run
from shutil import rmtree
from os import remove

BUILD_FOLDER = "build"

try:
    rmtree(BUILD_FOLDER)
except:
    pass

try:
    run(f'cmake -S . -B {BUILD_FOLDER} -Wno-dev', shell=True, check=True)
    run(f'cmake --build {BUILD_FOLDER}', shell=True, check=True)
    run(f'valgrind --leak-check=full {BUILD_FOLDER}/water_trigger_integration_test > test.result', shell=True, check=True)
    remove("test.result")
except:
    pass
