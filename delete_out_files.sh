# This will delete all .out binary files in subfolders

delete_out_files() {
    local dir="$1"
    local file
    for file in "$dir"/*; do
        if [ -d "$file" ]; then
            # Recursively enter subdirectories
            delete_out_files "$file"
        elif [[ "$file" == *.out ]]; then
            # Delete files ending with .out
            rm -f "$file"
            echo "Deleted: $file"
        fi
    done
}

delete_out_files "$(pwd)"
