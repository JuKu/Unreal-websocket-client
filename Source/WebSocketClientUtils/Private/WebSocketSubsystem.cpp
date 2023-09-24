// Fill out your copyright notice in the Description page of Project Settings.


#include "WebSocketSubsystem.h"
#include "WebSocketsModule.h" // Module definition
#include "IWebSocket.h"       // Socket definition

void UWebSocketSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Load WebSocket module, because it's not loaded automatically
	if (!FModuleManager::Get().IsModuleLoaded("WebSockets")) {
		FModuleManager::Get().LoadModule("WebSockets");
	}
}

void UWebSocketSubsystem::Deinitialize()
{
	Disconnect();
	Super::Deinitialize();
}

void UWebSocketSubsystem::BindHandlers()
{
	// We bind all available events
	WebSocket->OnConnected().AddLambda([]() -> void {
		// This code will run once connected.
		UE_LOG(LogTemp, Warning, TEXT("Connected"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Connected"));
	});

	WebSocket->OnConnectionError().AddLambda([](const FString& Error) -> void {
		// This code will run if the connection failed. Check Error to see what happened.
		UE_LOG(LogTemp, Warning, TEXT("Connection Error"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Connection Error"));
		});

	WebSocket->OnMessage().AddLambda([](const FString& Message) {
		UE_LOG(LogTemp, Log, TEXT("Received message from websocket server: \"%s\"."), *Message);
	});

	WebSocket->OnClosed().AddLambda([](int32 StatusCode, const FString& Reason, bool bWasClean) -> void {
		// This code will run when the connection to the server has been terminated.
		// Because of an error or a call to Socket->Close().

		UE_LOG(LogTemp, Warning, TEXT("Connection Closed"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Connection Error"));
		});
}

void UWebSocketSubsystem::ConnectWithProtocol(FString ServerURL, FString ServerProtocol)
{
	WebSocket = FWebSocketsModule::Get().CreateWebSocket(ServerURL, ServerProtocol);

	// add handlers
	this->BindHandlers();

	UE_LOG(LogTemp, Warning, TEXT("Connecting..."));
	WebSocket->Connect();
}

void UWebSocketSubsystem::Connect(FString ServerURL)
{
	WebSocket = FWebSocketsModule::Get().CreateWebSocket(ServerURL);

	// add handlers
	this->BindHandlers();

	UE_LOG(LogTemp, Warning, TEXT("Connecting..."));
	WebSocket->Connect();
}

void UWebSocketSubsystem::Disconnect()
{
	if (WebSocket.IsValid()) {
		if (WebSocket->IsConnected()) {
			WebSocket->Close();
		}
	}
}

void UWebSocketSubsystem::SendMessage(FString msg)
{
	WebSocket->Send(msg);
}

bool UWebSocketSubsystem::isConnected()
{
	return WebSocket.IsValid() && WebSocket->IsConnected();
}
