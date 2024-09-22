Hindsight: There are many aspects of this project I could clean up or fix or do differently if given the chance. 
For example, better documentation or using a facade software pattern to allow me to more quickly implement a better graphical interface in the furtue

The goal of this project was to build a larger project, learn C++, objects, and get a better understanding of videeo game developmet.
3 Choices is a turn based RPG. The game has no typical Graphical interface and was insted implemented using print statements and a
Machines's terminal app. 

The game starts out with a brief optional turuorial followed by a character creator. Every entity in this game has 3 attributes- speed,health, and attack.
Similar to other turned based games, speed makes your character take turbs faster, health makes your character take more damage, and attack makes your character deal more damage.
Every entity also has 3 skills. In the character creator, you can choose from a randomized selection your starting skills. After you create your character, you set out to on your journey.
I find it best to think of the world as a tower with each floor having three rooms. After you complete a battle or event, you will be given 3 choices as to where you want to go next, hence
the name 3 choices. Each room has enemies and on certain floors there will be minibosses and bosses that have larger stats and mor powerful abilities. Each time you defeat a room you will be
given an amount of attributes to spend. You will also be given 3 skill choices based on the enemies you just defeated. There are multiple low ranked enemies, mini bosses, and bosses, each with their
own skills. Each enemy also has a pool of skills to choose from for its "type". For example, a rhino on floor one could have different skills than a rhino on floor two. This was my attempt at creating a dynamic 
play loop that encourages the player to find their favorite skills and engage with unique battles. The game theoretically goes on forever until you die or quit.
