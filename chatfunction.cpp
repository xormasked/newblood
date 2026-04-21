using Chat = void( __fastcall* )( __int64 a1, unsigned int a2 );

inline Chat chat = nullptr;

void send_chat( __int64 message, int chattype )
{
    chat
    (
        message,
        chattype // <- 0 = all chat, 1 = team chat
    );
}
