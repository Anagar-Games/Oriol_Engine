# Script for build framework Oriol
# Copyright (c) 2025 Anagar Games

import subprocess
import os

def build_cmake_project(build_dir="Out"):
    if not os.path.exists(build_dir):
        os.makedirs(build_dir)
        print(f"Create Directory: {build_dir}")

    original_dir = os.getcwd()
    os.chdir(build_dir)

    try:
        result_cmake = subprocess.run(
            ["cmake", ".."],
            check=True,
            capture_output=True,
            text=True
        )
        if result_cmake.stderr:
            print("CMake errors:\n", result_cmake.stderr)

        print("Build project...")
        result_build = subprocess.run(
            ["cmake", "--build", "."],
            check=True,
            capture_output=True,
            text=True
        )

        if result_build.stderr:
            print("Build errors:\n", result_build.stderr)

        print("Build successful!")

    except subprocess.CalledProcessError as e:
        print(f"Errors: {e}")
        print("stdout:", e.stdout)
        print("stderr:", e.stderr)
    except FileNotFoundError:
        print("CMake not found!")
    finally:
        os.chdir(original_dir)

if __name__ == "__main__":
    build_cmake_project()
