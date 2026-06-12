include("${_build_cmake_local}")

find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

set(PROTO_DIR "${CMAKE_CURRENT_SOURCE_DIR}/PiSubmarine/Video/Subscription/Grpc/Api")
set(PROTO_FILE "${PROTO_DIR}/VideoSubscriptionService.proto")
set(GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(PROTO_SRCS
        "${GENERATED_DIR}/VideoSubscriptionService.pb.cc"
        "${GENERATED_DIR}/VideoSubscriptionService.grpc.pb.cc")
set(PROTO_HDRS
        "${GENERATED_DIR}/VideoSubscriptionService.pb.h"
        "${GENERATED_DIR}/VideoSubscriptionService.grpc.pb.h")

add_custom_command(
        OUTPUT ${PROTO_SRCS} ${PROTO_HDRS}
        COMMAND $<TARGET_FILE:protobuf::protoc>
        ARGS
        --proto_path "${PROTO_DIR}"
        --cpp_out "${GENERATED_DIR}"
        --grpc_out "${GENERATED_DIR}"
        --plugin=protoc-gen-grpc=$<TARGET_FILE:gRPC::grpc_cpp_plugin>
        "${PROTO_FILE}"
        DEPENDS "${PROTO_FILE}"
        VERBATIM)

message("Adding library: ${PISUBMARINE_MODULE_NAME}")
add_library(${PISUBMARINE_MODULE_NAME}
        "../public/PiSubmarine/Video/Subscription/Grpc/Api/VideoSubscriptionService.h"
        ${PROTO_SRCS}
        ${PROTO_HDRS})
target_include_directories(${PISUBMARINE_MODULE_NAME} PUBLIC "../public" "${GENERATED_DIR}")
PiSubmarineInitTarget(${PISUBMARINE_MODULE_NAME})
target_link_libraries(${PISUBMARINE_MODULE_NAME} PUBLIC gRPC::grpc++ protobuf::libprotobuf)
