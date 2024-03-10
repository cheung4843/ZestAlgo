import os


def count_files(directory):
    total_files = 0

    for root, dirs, files in os.walk(directory):
        total_files += len(files)

    return total_files


if __name__ == "__main__":
    target_directory = "docs"

    num_files = count_files(target_directory)

    print(f"The number of files in the directory '{target_directory}' is: {num_files}")
