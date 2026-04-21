using Chat = void( __fastcall* )( __int64 a1, unsigned int a2 );

inline Chat chat = nullptr;

chat = reinterpret_cast< Chat >( Memory::image_base + 0x65EA810 );

void send_chat( __int64 message, int chattype )
{
    chat
    (
        message,
        chattype // <- 0 = all chat, 1 = team chat
    );
}
