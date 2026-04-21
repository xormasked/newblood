    using SetGlobalMatrix = void( __fastcall* )( entity* a1, havok::Vec4 a2, char a3 );

    inline SetGlobalMatrix set_global_matrix = nullptr;

    set_global_matrix = reinterpret_cast< SetGlobalMatrix >( Memory::image_base + 0x1FF4D40 );

void set_origin( havok::Vec4 location )
{
    if ( !Memory::valid_pointer( this ) ) return;

    set_global_matrix
    (
        this, // <- entity class
        location,
        1
    );
}
