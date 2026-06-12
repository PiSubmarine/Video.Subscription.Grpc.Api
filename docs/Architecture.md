# Video.Subscription.Grpc.Api

`PiSubmarine.Video.Subscription.Grpc.Api` contains the gRPC/protobuf contract shared by video subscription clients and servers.

## Responsibility

This module owns:

- the protobuf schema for video subscription RPCs
- generated protobuf message types
- generated gRPC service and stub types

It does not own:

- lease issuance or validation logic
- video control business logic
- subscription state storage
- GStreamer pipeline behavior

## Scope

The contract is responsible only for associating a valid video lease with a client RTP endpoint.

The first version intentionally supports:

- unicast RTP
- explicit lease id
- explicit endpoint host and port

It intentionally does not define:

- RTCP
- codec negotiation
- SDP exchange
- stream profile or focus control
- transport-specific endpoint implementation types
