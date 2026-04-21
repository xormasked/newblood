struct _BoneInfo {
private:
    char pad1[ 0x18 ];
public:
    uint64_t EncryptedEntity;
private:
    char pad2[ 0x34 ];
public:
    uint32_t BipedBoneID;
};

typedef void ( *GetBonePos_t )( _BoneInfo*, __m128* );

Vector3 get_bone_pos_by_id( uint32_t bone_hash )
{

    if ( !Memory::valid_pointer( this ) ) return; // <- pawn class.

    static GetBonePos_t GetBonePos = reinterpret_cast< GetBonePos_t >( Memory::image_base + 0x4064F50 );

    __m128 output{ };

    const uint64_t enc = RPM<uint64_t>(reinterpret_cast<uint64_t>( this ) + 0x18 ); // <- Ubi no longer uses skeleton_component from Entity->component list. They now use the encrypted Entity value. Remember that.

    _BoneInfo buffer{ };
    buffer.EncryptedEntity = enc;
    buffer.BipedBoneID = bone_hash;

    utils::spoof_call( GetBonePos, &buffer, &output ); // <- need to use spoof_call or you will crash.

    return Vector3
          (
          output.m128_f32[ 0 ],
          output.m128_f32[ 1 ],
          output.m128_f32[ 2 ]
          );

}
