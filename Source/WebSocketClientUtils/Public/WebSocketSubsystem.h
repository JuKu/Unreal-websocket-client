// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WebSocketsModule.h" // Module definition
#include "IWebSocket.h"       // Socket definition
#include "WebSocketSubsystem.generated.h"

/**
 * A subsystem which provides functionality to open WebSocket connections to a websocket server.
 */
UCLASS()
class WEBSOCKETCLIENTUTILS_API UWebSocketSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/*UFUNCTION(BlueprintCallable, meta = (DisplayName = "Connect to WebSocket server", Keywords = "WebSocket"), Category = "WebSocket")*/
	//void Connect();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Connect WebSocket with Protocol", Keywords = "WebSocket"), Category = "WebSocket")
		void ConnectWithProtocol(FString ServerURL, FString ServerProtocol);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Connect WebSocket", Keywords = "WebSocket"), Category = "WebSocket")
		void Connect(FString ServerURL);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Disconnect WebSocket", Keywords = "WebSocket"), Category = "WebSocket")
		void Disconnect();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Send message", Keywords = "WebSocket"), Category = "WebSocket")
		void SendMessage(FString msg);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "isConnected?", Keywords = "WebSocket"), Category = "WebSocket")
		bool isConnected();

	/** Override to control if the Subsystem should be created at all.
	 * For example you could only have your system created on servers.
	 * It's important to note that if using this is becomes very important to null check whenever getting the Subsystem.
	 *
	 * Note: This function is called on the CDO prior to instances being created!
	 */
	// virtual bool ShouldCreateSubsystem(UObject* Outer) const { return true; }

	// Begin USubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// End USubsystem

	TSharedPtr<IWebSocket> WebSocket;

protected:
	//TSharedPtr<IWebSocket> Socket;

private:
	void BindHandlers();
	
};
