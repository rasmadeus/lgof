#include "flyweight.h"
#include <cassert>
#include <iostream>

using namespace lgof;

TreeData::TreeData(TreeType type, int height)
    : m_treeType{ type }
    , m_height{ height }
{
}

TreeType TreeData::treeType() const
{
    return m_treeType;
}

int TreeData::height() const
{
    return m_height;
}

TreeData const &TreeDataFactory::find(TreeType treeType, int height)
{
    auto key = std::make_pair(treeType, height);

    if (auto const it = m_treeData.find(key); it != m_treeData.cend())
    {
        return it->second;
    }
    else
    {
        auto const [insertedIt, ok] = m_treeData.emplace(std::move(key), TreeData{ treeType, height });
        assert(ok);
        return insertedIt->second;
    }
}

int TreeDataFactory::size() const
{
    return static_cast<int>(m_treeData.size());
}

Tree::Tree(int x, int y, TreeData const &treeData)
    : m_x{ x }
    , m_y{ y }
    , m_treeData{ treeData }
{
}

void Tree::draw() const
{
    std::cout
        << m_x
        << m_y
        << static_cast<std::underlying_type<TreeType>::type>(m_treeData.treeType())
        << m_treeData.height();
}

void Forest::addTree(int x, int y, TreeType treeType, int height)
{
    m_trees.emplace_back(Tree{ x, y, m_treeDataFactory.find(treeType, height) });
}

void Forest::draw() const
{
    for (auto const &tree : m_trees)
    {
        tree.draw();
    }
}

int Forest::treeDataSize() const
{
    return m_treeDataFactory.size();
}
