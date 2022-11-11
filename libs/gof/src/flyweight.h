#pragma once

#include <gof_export.h>
#include <map>
#include <string>
#include <utility>
#include <vector>

namespace lgof
{
    enum class TreeType
    {
        Birch,
        Oak,
    };

    class GOF_EXPORT TreeData
    {
    public:
        TreeData(TreeType type, int height);
        TreeType treeType() const;
        int height() const;

    private:
        TreeType const m_treeType;
        int const m_height;
    };

    class TreeDataFactory
    {
    public:
        GOF_EXPORT TreeData const &find(TreeType treeType, int height);
        GOF_EXPORT int size() const;

    private:
        std::map<std::pair<TreeType, int>, TreeData> m_treeData;
    };

    class Tree
    {
    public:
        GOF_EXPORT Tree(int x, int y, TreeData const &treeData);
        GOF_EXPORT void draw() const;

    private:
        int const m_x;
        int const m_y;
        TreeData const &m_treeData;
    };

    class Forest
    {
    public:
        GOF_EXPORT void addTree(int x, int y, TreeType treeType, int height);
        GOF_EXPORT void draw() const;
        GOF_EXPORT int treeDataSize() const;

    private:
        TreeDataFactory m_treeDataFactory;
        std::vector<Tree> m_trees;
    };
}
