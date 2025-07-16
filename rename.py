import os
import sys
import re
import uuid

# Usage: python rename.py TargetName
if len(sys.argv) != 2:
    print("Usage: python rename.py TargetName")
    sys.exit(1)

target_name = sys.argv[1]
target_name_lower = target_name.lower()

# File extensions to process
target_exts = ['.json', '.txt', '.h', '.cpp', '.cmake', '.setreg']

# Collect all target files
def collect_files(root):
    file_list = []
    for dirpath, _, filenames in os.walk(root):
        for fname in filenames:
            ext = os.path.splitext(fname)[1]
            if ext in target_exts:
                file_list.append(os.path.join(dirpath, fname))
    return file_list

# Replace content in file
def replace_in_file(filepath, old, new, old_lower, new_lower):
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()
    content = content.replace(old, new)
    content = content.replace(old_lower, new_lower)
    # GUID replacement
    guid_pattern = r'\{[0-9A-Fa-f\-]{36}\}'
    content = re.sub(guid_pattern, lambda _: '{' + str(uuid.uuid4()).upper() + '}', content)
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(content)

# Rename file
def rename_file(filepath, old, new, old_lower, new_lower):
    dirpath, fname = os.path.split(filepath)
    new_fname = fname.replace(old, new).replace(old_lower, new_lower)
    new_path = os.path.join(dirpath, new_fname)
    if new_path != filepath:
        os.rename(filepath, new_path)
    return new_path

if __name__ == '__main__':
    root = os.path.dirname(os.path.abspath(__file__))
    files = collect_files(root)
    for f in files:
        replace_in_file(f, 'DefaultTemplateGem', target_name, 'defaulttemplategem', target_name_lower)
    # File renaming
    for f in files:
        rename_file(f, 'DefaultTemplateGem', target_name, 'defaulttemplategem', target_name_lower)