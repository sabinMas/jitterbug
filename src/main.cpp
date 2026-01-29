#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_sprite_ptr.h>
#include <bn_random.h>
#include <bn_vector.h>
#include <bn_keypad.h>

#include "bn_sprite_items_bug_sprite.h"

int main()
{
    // Random number generator
    bn::random rng = bn::random();

    // Initialize Butano
    bn::core::init();

    // Backdrop color (you can keep your original if you want)
    bn::backdrop::set_color(bn::color(24, 31, 29));

    // Vector of ladybug sprites
    bn::vector<bn::sprite_ptr, 50> bugs = {};

    // Main game loop
    while (true)
    {
        // Move all ladybug sprites randomly
        for (bn::sprite_ptr &ladybug : bugs)
        {
            bn::fixed new_x = ladybug.x() + rng.get_fixed(-1, 1);
            bn::fixed new_y = ladybug.y() + rng.get_fixed(-1, 1);

            ladybug.set_x(new_x);
            ladybug.set_y(new_y);
        }

        // If A is pressed, create a new ladybug and add it to the vector
        if (bn::keypad::a_pressed())
        {
            bugs.push_back(bn::sprite_items::bug_sprite.create_sprite());
        }

        // Update RNG and frame
        rng.update();
        bn::core::update();
    }
}
