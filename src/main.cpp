#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_sprite_ptr.h>

#include "bn_sprite_items_bug_sprite.h"

int main()
{
    bn::core::init();

    bn::backdrop::set_color(bn::color(24, 31, 29));

    bn::sprite_ptr ladybug = bn::sprite_items::bug_sprite.create_sprite();

    while (true)
    {
        bn::core::update();
    }
}