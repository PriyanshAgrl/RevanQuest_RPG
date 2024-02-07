#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function Prototype Declarations

void charCreation(char fName[], char lName[], int *archetype);
void stats(int *strength, int *agility, int *wisdom, int *charisma);
void displayCharacter(char fName[], char lName[], int archetype, int strength, int agility, int wisdom, int charisma);

// Decision making functions
void decision1( int *choice1, int *strength, int *agility, int *wisdom, int *charisma);
void decision2( int *choice2, int *strength, int *agility, int *wisdom, int *charisma);
void decision3( int *choice3, int *strength, int *agility, int *wisdom, int *charisma);
void decision4( int *choice4, int *strength, int *agility, int *wisdom, int *charisma);
void decision5( int *choice5, int *strength, int *agility, int *wisdom, int *charisma);
void decision6( int *choice6, int *strength, int *agility, int *wisdom, int *charisma);
void decision7( int *choice7, int *strength, int *agility, int *wisdom, int *charisma);
void decision8( int *choice8, int *strength, int *agility, int *wisdom, int *charisma);
void decision9( int *choice9, int *strength, int *agility, int *wisdom, int *charisma);
void decision10( int *choice10, int *strength, int *agility, int *wisdom, int *charisma);

// Function to simulate a dice roll
int rollDice(int sides) {
  return rand() % sides + 1;
}

// Battle Mechanics (will be updated in future)
void battleswitch(int archetype);
void rulerBattle();
void saberBattle();
void assassinBattle();
void casterBattle();

int main(void) {
  printf("--------------------------------------------------------\n");
  printf("\tWelcome to the Mystical Realm of Eldoria!\n");
  printf("--------------------------------------------------------\n");
  //Variable Declarations
  char fName[16], lName[16];
  int archetype;
  int strength, agility, wisdom, charisma;
  int choice1, choice2, choice3, choice4, choice5, choice6, choice7, choice8, choice9;
  
  //Function Calls
  charCreation(fName, lName, &archetype);
  stats(&strength, &agility, &wisdom, &charisma);
  displayCharacter(fName, lName, archetype, strength, agility, wisdom, charisma);

  printf("\n\t--- Prologue: In the Court of Eldoria ---\n\n");
  printf("The grand halls of Eldoria Castle echoed with calculated footsteps as you, %s, a seasoned mercenary, stepped into the court. The flickering torches cast shadows on the adorned walls, telling tales of the kingdom's glorious history.\nYour presence had been summoned by a royal decree, and as you approached the throne room, memories of your past deeds flooded your mind. The king, Adrian, had a reputation for fairness and wisdom, and you had crossed paths with the monarch on more than one occasion during his exploits.\nAs you entered the throne room, you found yourself bathed in the warm glow of the chandeliers hanging from the high vaulted ceiling. King Adrian sat upon his throne, an embodiment of regal authority. The air was thick with tension, and the scarse courtiers exchanged guarded glances.\n", fName);
  
  //Decision 1
  decision1(&choice1, &strength, &agility, &wisdom, &charisma);

  printf("\n\nNext to the emperor, a woman stood with her back straight, hands firmly placed on her hips. Her stature larger than most men were quite impressive. Clad entirely in black armor, she seemingly belonged to the King’s personal guards, the Scarlett Army. She held a sharp spear next to her.\n\nThe king observing you silently, finally spoke up, his dignified voice resonating through the chamber.\n\n“Greetings. I am Adrian Tepes, the King of the Eldoria Kingdom.”\nFormalities concluded swiftly.\n“Hmm... so you’re the hero of the rumors. %s, correct?”\n\nYou nodded, sensing the atmosphere beginning to buzz. Even in the unwavering eyes of the Guard Captain, there was a spark of interest.\n\n“I heard that you would be younger than expected, but I never imagined you would be this young.”\n“Should I take this as a compliment?”\n“Yes..., Guard Captain.”\n\nSuddenly, the Emperor turned to the Guard Captain. She respectfully inclined her waist.\n“Your command, Your Majesty.”\n“Lead everyone out. Ensure no one but %s and I remain in the chamber.”\n“As you command.”\n\nYour eyes widened. Suddenly, you couldn’t understand what was happening. The Guard Captain, striding purposefully, addressed the people.\nThe already scarce people exited like a swift current. Only Ronan and the Emperor were left in the now-empty throne chamber. Thud. The sound of the door closing echoed in the vacuous space.\n\n‘I didn’t expect this.‘ you thought.\n\nConfirming no one was around, the Emperor stood up.\n\n“I have a request for you. I want you to become a Revan for the Kingdom.”\n“Revan?”\n“Yes, you may not be aware, but there’s an organization that has been causing quite a stir in recent years - The Shadow Guild. The darkness that is eating away at the empire...”\n", fName, fName);
  
  //Decision 2
  decision2(&choice2, &strength, &agility, &wisdom, &charisma);

// . . . to be continued . . .
  return 0;
}

// Function to handle Character Creation
void charCreation(char fName[16], char lName[16], int *archetype) {
  printf("\nCharacter Creation\n");
  printf("Enter Your Character's First Name : ");
  scanf(" %15s", fName);
  printf("Enter Your Character's Last Name : ");
  scanf(" %15s", lName);
  printf("\nYour Character's Name is %s %s\n", fName, lName);

  // Class Selection
  printf("\nChoose Your Character Class: \n");
  printf(" 1. Saber\n 2. Assassin\n 3. Caster\n ");
  do {
    printf("\nEnter the number of your chosen class : ");
    scanf(" %d", archetype);
    while (getchar() != '\n'); // Clear input buffer
    switch (*archetype) {
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
  } while (*archetype < 0 || *archetype > 3);
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

// Function for the first Choice
void decision1( int *choice1, int *strength, int *agility, int *wisdom, int *charisma) {
  printf("\nKing Eldor's gaze met your's as the you stepped into the throne room. The court felt eerie with silence, and you faced a pivotal decision.\n");
  printf(" 1. Bow down respectfully to the king.\n 2. Keenly analyze the room and security measures.\n 3. Lock eyes the king, analyzing his body language and authority.\n");
  printf("\nEnter the number of your chosen action : ");
  scanf(" %d", choice1);
  while(getchar() != '\n'); // Clear input buffer
  do {
    switch (*choice1) {
      case 1: {
        printf("\nYou bowed down to the king, your eyes fixed on the ground below throne. The king smiled with admiration.\n");
        (*wisdom)++;
        (*charisma)++;
        printf("\n**Attributes acquired**\n- Wisdom +1, \n- Charisma +1");
        break;
      }
      case 2: {
        printf("\nYou observed the court with a critical eye, and noted the positions of the guards, the exits, and the subtle tensions among the courtiers. The king's eyes revealed a hint of approval, acknowledging your astuteness.\n");
        (*strength)++;
        (*agility)++;
        printf("**Attributes acquired**\n- Strength +1 \n- Agility +1");
        break;
      }
      case 3: {
        printf("\nYou held your eyes fixed on the king, analyzing his posture and aura. The king ....\n");
        (*wisdom)++;
        (*strength)++;
        printf("\n**Attributes acquired**\n- Wisdom +1, \n- Strength +1");
        break;
      }
      default:
        printf("Invalid choice. Please try again.");
        break;
    }
  } while (*choice1 < 1 || *choice1 > 3);
}

void decision2( int *choice2, int *strength, int *agility, int *wisdom, int *charisma) {
  printf("\n You find yourself drawn into a shadowy conspiracy. The King reveals the existence of the Shadow Guild, an organization threatening Eldoria's peace. The burden of becoming a Revan, a defender against this darkness, falls upon you.\n");
  printf(" 1. Bow down respectfully to the king.\n 2. Keenly analyze the room and security measures.\n 3. Lock eyes the king, analyzing his body language and authority.\n");
  printf("\nEnter the number of your chosen action : ");
  scanf(" %d", choice2);
  while(getchar() != '\n'); // Clear input buffer
  do {
    switch (*choice2) {
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
  } while (*choice2 < 1 || *choice2 > 3);
}

void battleswitch(int archetype) {
  switch (archetype) {
    case 0:
      rulerBattle();
      return;
    case 1:
      saberBattle();
      return;
    case 2:
      assassinBattle();
      return;
    case 3:
      casterBattle();
      return;
    default:
      return;
  }
}

// Ruler battle function
void rulerBattle() {
  printf("You are engaged in battle as a Ruler!\n");
  // Need to implement Ruler-specific battle mechanics and options
  // Example:
  // - Attack: Deal physical damage
  // - Heavy Strike: Deal high physical damage with a chance of lowering enemy defense
  // - Defend: Increase defense for a turn
}

// Saber battle function
void saberBattle() {
  printf("You are engaged in battle as a Saber!\n");
  // Need to implement Saber-specific battle mechanics and options
  // Example:
  // - Attack: Deal physical damage
  // - Heavy Strike: Deal high physical damage with a chance of lowering enemy defense
  // - Defend: Increase defense for a turn
}

// Assassin battle function
void assassinBattle() {
  printf("You are engaged in battle as an Assassin!\n");
  // Need to implement Assassin-specific battle mechanics and options
  // Example:
  // - Attack: Deal physical damage
  // - Backstab: Perform a critical hit with increased damage
  // - Evasion: Increase evasion chance for a turn
}

// Caster battle function
void casterBattle() {
  printf("You are engaged in battle as a Caster!\n");
  // Need to implement Caster-specific battle mechanics and options
  // Example:
  // - Cast Spell: Use Blaze to deal damage
  // - Mana Shield: Restore mana points for future spellcasting
  // - Defend: Increase magical defense for a turn
}