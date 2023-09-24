// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WebSocketsModule.h" // Module definition
#include "IWebSocket.h"       // Socket definition
#include "WebSocketFunctionLibrary.generated.h"

/**
 * Expose the WebSocket functionality from UE5.
 * 
 * See also: https://unrealcommunity.wiki/websocket-client-cpp-5vk7hp9e .
 */
UCLASS()
class WEBSOCKETCLIENTUTILS_API UWebSocketFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*UFUNCTION(BlueprintPure, meta = (DisplayName = "Create WebSocket Client", Keywords = "WebSocket"), Category = "WebSocket")
		static TSharedPtr<IWebSocket> WebSocketCreateClient();*/

	/*UFUNCTION(BlueprintPure, meta = (DisplayName = "WebSocket Connect", Keywords = "WebSocket"), Category = "WebSocket")
		static FString WebSocketConnect();*/
	
};
