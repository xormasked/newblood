    using TeamId = __int64 ( __fastcall* )( controller* a1 );

    inline TeamId team_id = nullptr;

    team_id = reinterpret_cast< TeamId >( Memory::image_base + 0x4898110 );

        auto get_team_id( ) -> __int64 {
            if ( !Memory::valid_pointer( this ) ) return 0;

            return utils::spoof_call( team_id, this ); // <- controller class, Need to use spoof_call for this cause you will crash if u dont
        }
