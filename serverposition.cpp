inline constexpr uintptr_t server_position_rva = 0xFB03A0; // <- hook this. There are 2 args. ( pawn* a1, unknown a2 )

// Cant leak everything. But i can give some pointers.
// Look at how a2 is handles within the function, look at it in ida.
// a2 contains pointers to things like server pos, velocity, and other flags.
// All very useful exploits for hvh
// Have fun! :)

// remember when hooking.
// Every pawn in the controller list will be passed into the first arg.
// So add a condition so if the pawn != your local pawn, dont do anything and call the function as normal.
// If pawn == your local pawn, mess with a2 to do whatever your heart desires.
