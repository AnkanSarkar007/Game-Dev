This lists the various features of the project.

Firstly, the parabolic motion is implemented. Default value of velocity in vertical direction is set to 100 while gravity is set to 5.

Next, the collisions between bubble and bullet and also between bubble and shooter is introduced.

Bubbles of various sizes are introduced.

Whenever a bigger bubble is hit with a bullet, it splits into two smaller bubbles of half the radius.

The horizontal velocity of the newly created bubbles is opposite to each other while the vertical velocity is the same (which is opposite to the vertical velocity of the bigger bubble),
but, if the radius of the bubble equals the threshold value, then it just vanishes. The bullet also vanishes after hitting any bubble.

The score counter gets incremented whenever a bullet hits a bubble.

The time counter keeps track of time (in seconds), the maximum time limit for the game is tmax seconds beyond which the game ends.

The bullet counter keeps track of the number of bullets left in your inventory. It is initially set to fmax.

A health counter is also provided which is initially set to hmax "units". Whenever a bubble touches the shooter, its health reduces by 5 "units" for each STEP_TIME the bubble is in contact
with the shooter. Thus, a longer duration touch will lead to more health loss than a shorter duration touch. If health drops to zero, the game ends.

The game has 5 levels. Depeneding on the choice fmax, hmax, tmax and bubble speeds are changed accordingly.

Finally, if no bubble remains on the screen, the game is won!