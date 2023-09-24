// Fill out your copyright notice in the Description page of Project Settings.


#include "WebSocketFunctionLibrary.h"
#include "WebSocketsModule.h" // Module definition
#include "IWebSocket.h"       // Socket definition

/*TSharedPtr<IWebSocket> UWebSocketFunctionLibrary::WebSocketCreateClient()
{
	const FString ServerURL = TEXT("ws://127.0.0.1:3000/"); // Your server URL. You can use ws, wss or wss+insecure.
	const FString ServerProtocol = TEXT("ws");

	TSharedPtr<IWebSocket> Socket = FWebSocketsModule::Get().CreateWebSocket(ServerURL, ServerProtocol);
	return Socket;
}*/