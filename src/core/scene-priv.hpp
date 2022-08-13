#pragma once
#include <wayfire/scene.hpp>


namespace wf
{
namespace scene
{
struct root_node_t::priv_t
{
    std::shared_ptr<floating_inner_node_t> system_nodes;

    std::vector<node_ptr> active_keyboard_nodes;

    // Nodes with ACTIVE_USER_INPUT set (excluding normal pointer focus).
    std::vector<node_ptr> active_pointer_nodes;

    /**
     * Iterate over the scenegraph and compute nodes which have active keyboard
     * input. Send enter/leave events accordingly.
     */
    void update_active_nodes(root_node_t *root);

    /**
     * Forward the wlr_keyboard event to the scene nodes.
     */
    void handle_key(wlr_event_keyboard_key ev);
};
}
}
