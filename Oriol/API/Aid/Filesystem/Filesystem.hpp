// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_FILESYSTEM_HPP
#define OL_FILESYSTEM_HPP

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace OL
{
    class Filesystem
    {
    public:
        Filesystem() = default;
        ~Filesystem() = default;

        bool CreateDirectory(const std::string& path_a);
        bool Remove(const std::string& path_a);
        bool Rename(const std::string& old_path_a,
                    const std::string& new_path_a);
        bool Exists(const std::string& path_a) const;

        bool Copy(const std::string& from_a,
                  const std::string& to_a,
                  bool recursive_a = false);

        std::vector<std::string> ListDirectory(const std::string& path_a) const;
        std::string GetAbsolutePath(const std::string& path_a) const;

        bool IsDirectory(const std::string& path_a) const;
        bool IsFile(const std::string& path_a) const;

        uintmax_t FileSize(const std::string& path_a) const;

    private:
        void _CopyDirectoryRecursive(const std::filesystem::path& from_a,
                                     const std::filesystem::path& to_a);
    };
} // namespace OL
#endif
