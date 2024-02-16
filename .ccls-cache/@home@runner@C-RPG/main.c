#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure for characters
struct chState {
  int hp;  // Health points
  int mp;  // Mana points
  int xp;  // Experience points
  int lvl; // Level
};

typedef struct Character {
  char fName[16];
  char lName[16];
  int archetype; // Class of the character
  int strength;
  int agility;
  int wisdom;
  int charisma;
  struct chState state;
} ch;

// Function Prototype Declarations
void charCreation(ch *player);
void stats(int *strength, int *agility, int *wisdom, int *charisma);
void displayCharacter(char fName[], char lName[], int archetype, int strength, int agility, int wisdom, int charisma);

// Decision making functions
void decision1(int choice[0], int *strength, int *agility, int *wisdom, int *charisma);
void decision2(int choice[1], int *strength, int *agility, int *wisdom, int *charisma);
void decision3(int choice[2], int *strength, int *agility, int *wisdom, int *charisma);
void decision4(int choice[3], int *strength, int *agility, int *wisdom, int *charisma);
void decision5(int choice[4], int *strength, int *agility, int *wisdom, int *charisma);
void decision6(int choice[5], int *strength, int *agility, int *wisdom, int *charisma);
void decision7(int choice[6], int *strength, int *agility, int *wisdom, int *charisma);
void decision8(int choice[7], int *strength, int *agility, int *wisdom, int *charisma);
void decision9(int choice[8], int *strength, int *agility, int *wisdom, int *charisma);
void decision10(int choice[9], int *strength, int *agility, int *wisdom, int *charisma);

// Function to simulate a dice roll
int rollDice(int sides) {
  return rand() % sides + 1;
}

// Battle Mechanics (will be updated in future)
void displayChState(ch *character);
void battleExperience(ch *player, ch *enemy);
void battleswitch(int archetype, ch *player, ch *enemy);
void rulerBattle(ch *player, ch *enemy);
void saberBattle(ch *player, ch *enemy);
void assassinBattle(ch *player, ch *enemy);
void casterBattle(ch *player, ch *enemy);

int main(void) {
  printf("--------------------------------------------------------\n");
  printf("\tWelcome to the Mystical Realm of Eldoria!\n");
  printf("--------------------------------------------------------\n");
  //Variable Declarations
  ch player;
  int choice[24];

  //Function Calls
  charCreation(&player);
  stats(&player.strength, &player.agility, &player.wisdom, &player.charisma);
  displayCharacter(player.fName, player.lName, player.archetype, player.strength, player.agility, player.wisdom, player.charisma);
  printf("\n\t--- Prologue: In the Court of Eldoria ---\n\n");
  printf("The grand halls of Eldoria Castle echoed with calculated footsteps as you, %s, a seasoned mercenary, stepped into the court. The flickering torches cast shadows on the adorned walls, telling tales of the kingdom's glorious history.\nYour presence had been summoned by a royal decree, and as you approached the throne room, memories of your past deeds flooded your mind. The king, Adrian, had a reputation for fairness and wisdom, and you had crossed paths with the monarch on more than one occasion during his exploits.\nAs you entered the throne room, you found yourself bathed in the warm glow of the chandeliers hanging from the high vaulted ceiling. King Adrian sat upon his throne, an embodiment of regal authority. The air was thick with tension, and the scarse courtiers exchanged guarded glances.\n", player.fName);

  //Decision 1
  decision1(&choice[0], &player.strength, &player.agility, &player.wisdom, &player.charisma);
  printf("\n\nNext to the emperor, a woman stood with her back straight, hands firmly placed on her hips. Her stature larger than most men were quite impressive. Clad entirely in black armor, she seemingly belonged to the King’s personal guards, the Scarlett Army. She held a sharp spear next to her.\n\nThe king observing you silently, finally spoke up, his dignified voice resonating through the chamber.\n\n >> Greetings. I am Adrian Tepes, the King of the Eldoria Kingdom.\n\nFormalities concluded swiftly.\n\n >> Hmm... so you’re the hero of the rumors. %s, correct?\n\nYou nodded, sensing the atmosphere beginning to buzz. Even in the unwavering eyes of the Guard Captain, there was a spark of interest.\n\n >> I heard that you would be younger than expected, but I never imagined you would be this young.\n >> Should I take this as a compliment?\n >> Yes..., Guard Captain.\n\nSuddenly, the Emperor turned to the Guard Captain. She respectfully inclined her waist.\n\n >> Your command, Your Majesty.\n >> Lead everyone out. Ensure no one but %s and I remain in the chamber.\n >> As you command.\n\nYour eyes widened. Suddenly, you couldn’t understand what was happening. The Guard Captain, striding purposefully, addressed the people.\nThe already scarce people exited like a swift current. Only you and the Emperor were left in the now-empty throne chamber. Thud. The sound of the door closing echoed in the vacuous space.\n\n‘I didn’t expect this.‘ you thought.\n\nConfirming no one was around, the Emperor stood up.\n\n >> I have a request for you. I want you to become a Revan for the Kingdom.\n >> Revan?\n >> Yes, you may not be aware, but there’s an organization that has been causing quite a stir in recent years - The Shadow Guild. The darkness that is eating away at the empire...\n", player.fName, player.fName);

  //Decision 2
  decision2(&choice[1], &player.strength, &player.agility, &player.wisdom, &player.charisma);

  // Testing for Battle Mechanics
  ch enemy = {"Shadow", "Member", 1, 10, 10, 10, 10, {50, 0, 0, 1}};
  battleswitch(player.archetype, &player, &enemy);
// . . . to be continued . . . //
  
  return 0;
}
// Function to handle Character Creation
void charCreation(ch *player) {
  printf("\nCharacter Creation\n");
  printf("Enter Your Character's First Name : ");
  scanf(" %15s", player->fName);
  printf("Enter Your Character's Last Name : ");
  scanf(" %15s", player->lName);
  printf("\nYour Character's Name is %s %s\n", player->fName, player->lName);
  player->state.hp = 100;
  player->state.mp = 100;
  player->state.xp = 0;
  player->state.lvl = 1;
  
  // Class Selection
  printf("\nChoose Your Character Class: \n");
  printf(" 1. Saber\n 2. Assassin\n 3. Caster\n ");
  do {
    printf("\nEnter the number of your chosen class : ");
    scanf(" %d", &player->archetype);
    while (getchar() != '\n'); // Clear input buffer
    switch (player->archetype) {
      case 0:
        printf("You have chosen the Secret Class! You are now a Ruler.\n");
        break;
      case 1:
        printf("Great choice! You are now a Saber.\n");
        break;
      case 2:
        printf("Great choice! You are now an Assassin.\n");
        break;
      case 3:
        printf("Great choice! You are now a Caster.");
        break;
      default:
        printf("\nInvalid Choice! Please enter a valid integer for class.\n");
        break;
    }
  } while (player->archetype < 0 || player->archetype > 3);
}
// Function to handle Attribute Points Allocation
void stats(int *strength, int *agility, int *wisdom, int *charisma) {
  // Stats Selection
  printf("\nNow, distribute 10 Attribute Points across the following Stats: \n");
  printf("\nAttributes: \n");
  printf(" 1. Strength\n 2. Agility\n 3. Wisdom\n 4. Charisma\n");
  do {
    printf("Enter points for Strength :\t");
    scanf(" %d", strength);
    while (getchar() != '\n'); // Clear input buffer
    printf("Enter points for Agility :\t");
    scanf(" %d", agility);
    while (getchar() != '\n'); // Clear input buffer
    printf("Enter points for Wisdom :\t");
    scanf(" %d", wisdom);
    while (getchar() != '\n'); // Clear input buffer
    printf("Enter points for Charisma :\t");
    scanf(" %d", charisma);
    while (getchar() != '\n'); // Clear input buffer
    if (*strength + *agility + *wisdom + *charisma != 10 || (*strength < 0 || *agility < 0 || *wisdom < 0 || *charisma < 0)) {
      printf("\nInvalid points! Please enter 10 positive points in total.\n\n");
    }
  } while (*strength + *agility + *wisdom + *charisma != 10 || (*strength < 0 || *agility < 0 || *wisdom < 0 || *charisma < 0));
}
// Function to display the Character's Information
void displayCharacter(char fName[16], char lName[16], int archetype, int strength, int agility, int wisdom, int charisma) {
  // Displaying Character Summary
  printf("\nCharacter Summary:\n\n");
  printf("Name: %s %s\n", fName, lName);
  // Displaying Class
  switch (archetype) {
    case 0:
      printf("Class: Ruler.\n");
      break;
    case 1:
      printf("Class: Saber.\n");
      break;
    case 2:
      printf("Class: Assassin.\n");
      break;
    case 3:
      printf("Class: Caster.\n");
      break;
    default:
      // This case should not happen, but just in case
    break;
  }
  // Displaying Stats
  printf("\nStats:\n");
  printf("Strength: %d\n", strength);
  printf("Agility: %d\n", agility);
  printf("Wisdom: %d\n", wisdom);
  printf("Charisma: %d\n", charisma);
}
// Functions for the Choices
void decision1( int choice[0], int *strength, int *agility, int *wisdom, int *charisma) {
  printf("\nKing Eldor's gaze met your's as the you stepped into the throne room. The court felt eerie with silence, and you faced a pivotal decision.\n");
  printf(" 1. Bow down respectfully to the king.\n 2. Keenly analyze the room and security measures.\n 3. Lock eyes the king, analyzing his body language and authority.\n");
  printf("\nEnter the number of your chosen action : ");
  scanf(" %d", &choice[0]);
  while(getchar() != '\n'); // Clear input buffer
  do {
    switch (choice[0]) {
      case 1: {
        printf("\nYou bowed down to the king, your eyes fixed on the ground below throne. The king smiled with admiration.\n");
        (*wisdom)++;
        (*charisma)+=2;
        printf("\n**Attributes acquired**\n- Wisdom +1, \n- Charisma +2");
        break;
      }
      case 2: {
        printf("\nYou observed the court with a critical eye, and noted the positions of the guards, the exits, and the subtle tensions among the courtiers. The king's eyes revealed a hint of approval, acknowledging your astuteness.\n");
        (*strength)++;
        (*agility)+=2;
        printf("**Attributes acquired**\n- Strength +1 \n- Agility +2");
        break;
      }
      case 3: {
        printf("\nYou held your eyes fixed on the king, analyzing his posture and aura. The king ....\n");
        (*wisdom)++;
        (*strength)+=2;
        printf("\n**Attributes acquired**\n- Wisdom +1, \n- Strength +2");
        break;
      }
      default:
        printf("Invalid choice. Please try again.");
        break;
    }
  } while (choice[0] < 1 || choice[0] > 3);
}
void decision2( int choice[1], int *strength, int *agility, int *wisdom, int *charisma) {
  printf("\n You find yourself drawn into a shadowy conspiracy. The King reveals the existence of the Shadow Guild, an organization threatening Eldoria's peace. The burden of becoming a Revan, a defender against this darkness, falls upon you.\n");
  printf(" 1. Accept wholeheartedly.\n 2. Ask for Details.\n 3. Hesitate\n");
  printf("\nEnter the number of your chosen action : ");
  scanf(" %d", &choice[1]);
  while(getchar() != '\n'); // Clear input buffer
  do {
    switch (choice[1]) {
      case 1: {
        printf("\nAccept the mantle of Revan and vow to protect Eldoria from the Shadow Guild.\n");
        (*wisdom)++;
        (*charisma)++;
        printf("\n**Attributes acquired**\n- Wisdom +1, \n- Charisma +1");
        break;
      }
      case 2: {
        printf("\nSeek more details from the King about the nature, motives, and methods of the Shadow Guild.\n");
        (*strength)++;
        (*agility)++;
        printf("**Attributes acquired**\n- Strength +1 \n- Agility +1");
        break;
      }
      case 3: {
        printf("\nShare your reservations with the King, expressing the need for additional information before making a commitment.\n");
        (*wisdom)++;
        (*strength)++;
        (*charisma)--;
        printf("\n**Attributes acquired**\n- Wisdom +1, \n- Strength +1, \n- Charisma -1");
        break;
      }
      default:
        printf("Invalid choice. Please try again.");
        break;
    }
  } while (choice[1] < 1 || choice[1] > 3);
}

// Function to display character state
void displayChState(ch *character) {
  printf("\nCharacter: %s %s\n", character->fName, character->lName);
  printf("Health Points: %d\n", character->state.hp);
  printf("Mana Points: %d\n", character->state.mp);
}

// Function to award experience points to the player after a successful battle
void battleExperience(ch *player, ch *enemy) {
  // Base experience points gained after each battle
  int baseXP = 20;

  // Calculating experience points based on the player's current level
  int gainedXP = baseXP * player->state.lvl;

  // Adding bonus xp for defeating a stronger enemy
  if (enemy->state.lvl > player->state.lvl) {
    gainedXP += (enemy->state.lvl - player->state.lvl) * 5; // Extra XP for defeating higher level enemy
  }

  // Ensuring that the player cannot gain negative XP
  if (gainedXP < 0) {
    gainedXP = 0;
  }

  // Updating experience points to the player
  player->state.xp += gainedXP;
  printf("You gained %d experience points!\n", gainedXP);

  // Checking if the player has gained enough XP to level up
  if (player->state.xp >= 150 * player->state.lvl) {
    // Increasing player level
    player->state.lvl++;
    printf("Congratulations! You have reached level %d!\n", player->state.lvl);

    // Reset player XP for the next level
    player->state.xp = 0;

    // Increasing player's health or mana points for leveling up
    player->state.hp += player->state.lvl * 10;
    player->state.mp += player->state.lvl * 5;
  }
}

void battleswitch(int archetype, ch *player, ch *enemy) {
  switch (archetype) {
    case 0:
      printf("\n\nYou are engaged in battle as a Ruler!\n");
      rulerBattle(player, enemy);
      return;
    case 1:
      printf("\n\nYou are engaged in battle as a Saber!\n");
      saberBattle(player, enemy);
      return;
    case 2:
      printf("\n\nYou are engaged in battle as an Assassin!\n");
      assassinBattle(player, enemy);
      return;
    case 3:
      printf("\n\nYou are engaged in battle as a Caster!\n");
      casterBattle(player, enemy);
      return;
    default:
      return;
  }
}

// Ruler battle function
void rulerBattle(ch *player, ch *enemy) {
  // Need to implement Ruler-specific battle mechanics and options
}

// Saber battle function
void saberBattle(ch *player, ch *enemy) {
  while (player->state.hp > 0 && enemy->state.hp > 0) {
    displayChState(player);
    displayChState(enemy);
    // Saber-specific battle options
    printf("\nAvailable Moves:\n");
    printf("\t1. Attack\n");
    printf("\t2. Heavy Strike\n");
    printf("\t3. Defend\n");
    printf("\t4. Tactical Retreat\n");

    int move;
    printf("Enter your move: ");
    scanf("%d", &move);

    switch (move) {
      // Attack: Deal physical damage
      case 1: {
        printf("You perform a quick attack!\n");
        // Simulate damage dealt by the player
        int damage = (player->strength * player->state.lvl) + rollDice(10);
        if (rollDice(20) > 15 && enemy->strength < player->strength) { // approx 25% chance for a critical hit
          damage *= 2; // Double damage for a critical hit
          printf("Critical Hit! Your attack lands with devastating force, dealing %d damage!\nn", damage);
        } else {
          printf("Your attack connects, dealing %d damage!\n", damage);
        }
        enemy->state.hp -= damage;
        break;
      }
      // Heavy Strike: Deal high physical damage
      case 2: {
        printf("You execute a Heavy Strike, channeling all your strength into a powerful blow!\n");
        // Simulate damage dealt by the player
        int damage = (player->strength * player->state.lvl) + rollDice(18);
        printf("Your strike connects with incredible force, dealing %d damage!\n", damage);
        enemy->state.hp -= damage;
        break;
      }
      // Defence: Increase defense for a turn
      case 3: {
        printf("You assume a Defensive Stance, ready to deflect any incoming attacks!\n");
        // Simulate increased defence for the player
        player->state.hp += rollDice(10);
        printf("our defense is bolstered, providing added protection!\n");
        break;
      }
      // Tactical Retreat: Attempt to escape the battle
      case 4: {
        printf("You decide to make a Tactical Retreat, looking for a chance to rethink!\n");
        // Simulate the player attempting to run away
        if (rollDice(20) > 10) { // 50% chance of success
          printf("You manage to disengage from the battle and retreat to safety!\n");
          return;
        } else {
          printf("The enemy anticipates your move and blocks your retreat, leaving you no choice but to continue the fight!\n");
          break;
        }
      }
      default:
        printf("Your mind races, trying to decide your next move in the heat of battle.\n");
        break;
    }
    if (enemy->state.hp <= 0) {
      printf("With a final blow, you vanquish your foe, emerging victorious!\n");
      battleExperience(player, enemy);
      return;
    } else if (player->state.hp <= 0) {
      printf("You have been defeated by the enemy!\nGAME OVER");
      return;
    }
  }
  // Now, call the battle function for the enemy, and it will call the battle function for the player again... (until one of the HP reaches 0)
}

// Assassin battle function
void assassinBattle(ch *player, ch *enemy) {
  while (player->state.hp > 0 && enemy->state.hp > 0) {
  displayChState(player);
  displayChState(enemy);
  // Assassin-specific battle options
  printf("\nAvailable Tricks:\n");
  printf("\t1. Swift Slash\n");
  printf("\t2. Lethal Backstab\n");
  printf("\t3. Evasive Maneuver\n");
  printf("\t4. Vanish\n");

  int move;
  printf("Enter your move: ");
  scanf("%d", &move);

  switch (move) {
    // Attack: Deal physical damage
    case 1: {
      printf("You unleash a Swift Slash, striking with lightning speed!\n");
      // Simulate damage dealt by the player
      int damage = (player->agility * player->state.lvl) + rollDice(10);
      if (rollDice(20) > 15 && enemy->agility < player->agility) { // approx 25% chance for bonus speed
        damage += rollDice(6); // Add bonus damage for increased speed
        printf("Your agility allows you to strike faster, dealing %d damage!\n", damage);
      } else {
        printf("Your attack connects with precision, dealing %d damage!\n", damage);
      }
      enemy->state.hp -= damage;
      break;
    }
    // Lethal Backstab: Execute a devastating critical hit from behind the enemy
    case 2: {
      printf("You perform a Lethal Backstab, aiming for a vulnerable spot!\n");
      // Simulate damage dealt by the player
      int damage = (player->agility * player->state.lvl) + rollDice(18);
      if (rollDice(20) > 16) { // 20% chance for a critical hit
        damage *= 2; // Double the damage for a critical hit
        printf("Critical Hit! Your strike lands with lethal precision, dealing %d damage!\n", damage);
      } else {
        printf("Your precise strike hits home, dealing %d damage!\n", damage);
      }
      enemy->state.hp -= damage;
      break;
    }
    // Rolling to Evade: Try to Dodge the enemy's attack
    case 3: {
      printf("You execute an Evasive Maneuver, swiftly evading incoming attacks!\n\n");
      // Simulate increased defence for the player
      player->state.hp += rollDice(10);
      printf("Your agility allows you to gracefully dodge, providing additional protection!\n");
      break;
    }
    // Vanish: Attempt to disappear and escape the battle
    case 4: {
      printf("You use your surroundings to your advantage, disappearing into the shadows!\n");
      // Simulate the player attempting to go stealth mode and just vanish
      if (rollDice(20) > 10) {
        printf("You seamlessly blend into the darkness, vanishing from sight!\n");
        return;
      } else {
        printf("Your attempt to vanish is spoiled, and you remain visible to the enemy!\n");
        break;
      }
    }
    default:
      printf("Your mind races, trying to decide your next move in the heat of battle.\n");
      break;
  }
  if (enemy->state.hp <= 0) {
    printf("With a final slice, you silence your foe, emerging triumphant!\n");
    battleExperience(player, enemy);
    return;
  } else if (player->state.hp <= 0) {
    printf("You have been vanquished by the enemy!\nGAME OVER");
    return;
  }
}
  // Now, call the battle function for the enemy, and it will call the battle function for the player again... (until one of the HP reaches 0)
}

// Caster battle function
void casterBattle(ch *player, ch *enemy) {
  while (player->state.hp > 0 && enemy->state.hp > 0) {
    displayChState(player);
    displayChState(enemy);
    // Caster-specific battle options
    printf("\nAvailabe Spells:\n");
    printf("\t1. Blaze\n");
    printf("\t2. Replenish\n");
    printf("\t3. Protective Ward\n");
    printf("\t4. Teleport\n");

    int move;
    printf("Enter your move: ");
    scanf("%d", &move);

    switch (move) {
      // Cast Spell: Use Blaze to deal damage
      case 1: {
        printf("You cast a Blaze!\n");
        // Simulate damage dealt by the player
        int damage = (player->wisdom * player->state.lvl) + rollDice(10);
        printf("You deal %d damage!\n", damage);
        player->state.mp -= (damage/2);
        enemy->state.hp -= damage;
        
        break;
      }
      // Replenish: Restore mana points for future spellcasting
      case 2: {
        printf("You concentrate and replenish you mana!\n");
        // Simulate restoring mana points
        player->state.mp += rollDice(20);
        printf("Your Mana is replenished!\n");
        break;
      }
      // Protective Ward: Create a magical barrier for defense
      case 3: {
        printf("You create a Protective Ward, surrounding yourself with magical energy!\n");
        // Simulate increased magical defense
        player->state.hp += rollDice(10);
        player->state.mp -= rollDice(10);
      printf("The Protective Ward shields you from harm, increasing your defense!\n");
        break;
      }
      // Teleport: Instantly transport yourself to a different location
      case 4: {
        printf("As the chaos ensues, you cast Teleport, vanishing from your current position!\n");
        // Simulate the player attempting to run away
        if (rollDice(20) > 10) {
          printf("You reappear at a safe distance, evading the enemy's reach!\n");
          return;
        } else {
          printf("Your attempt to teleport fails, and you remain in your current location!\n");
          break;
        }
      }
      default:
        printf("Your mind races as you contemplate your next move in the heat of battle.\n");
        break;
    }
    if (enemy->state.hp <= 0) {
      printf("With a final incantation, you dispel your foe, emerging victorious!\n");
      battleExperience(player, enemy);
      return;
    } else if (player->state.hp <= 0) {
      printf("You have been defeated by the enemy!\nGAME OVER");
      return;
    }
  }
  // Now, call the battle function for the enemy, and it will call the battle function for the player again... (until one of the HP reaches 0)
}