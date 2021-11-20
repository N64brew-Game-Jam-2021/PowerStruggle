#ifndef __BEHAVIORS_H__
#define __BEHAVIORS_H__

#include <ecs.h>

enum class EnemyType : uint8_t {
    Shoot, // e.g. Grease-E
    Slash, // e.g. Mend-E
    Spinner, // e.g. Harv-E
    Ram, // e.g. Till-R
    Bomb, // e.g. Herb-E
    Beam, // e.g. Zap-E
    Multishot, // e.g. Gas-E
    Jet, // e.g. Wave-E
    Stab, // e.g. Drill-R
    Slam, // e.g. Smash-O
    Mortar, // e.g. Blast-E
    Flame, // e.g. Heat-O
};

#include <enemies/base.h>
#include <enemies/shoot.h>
#include <enemies/slash.h>
#include <enemies/spinner.h>

// Check if the target is in the sight radius and if so moves towards being the given distance from it
float approach_target(float sight_radius, float follow_distance, float move_speed, Vec3 pos, Vec3 vel, Vec3s rot, Vec3 target_pos);
// Creates an enemy of the given type and subtype at the given position
Entity* create_enemy(float x, float y, float z, EnemyType type, int subtype);
// Common initialiation routine for enemies
void init_enemy_common(BaseEnemyInfo *base_info, Model** model_out, HealthState* health_out);
// Common hitbox handling routine for enemies, returns true if the entity has run out of health
int handle_enemy_hits(Entity* enemy, ColliderParams& collider, HealthState& health_state);

#endif
