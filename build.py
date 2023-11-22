from subprocess import run
from shutil import rmtree

BUILD_FOLDER = "build"

try:
    rmtree(BUILD_FOLDER)
except:
    pass

try:
    run(f'cmake -S . -B {BUILD_FOLDER} -Wno-dev', shell=True, check=True)
    run(f'cmake --build {BUILD_FOLDER}', shell=True, check=True)
except:
    pass