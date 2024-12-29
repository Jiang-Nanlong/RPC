// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rpcheader.proto

#include "../include/rpcheader.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

namespace rpc {
  class RpcHeaderDefaultTypeInternal {
  public:
    ::google::protobuf::internal::ExplicitlyConstructed<RpcHeader> _instance;
  } _RpcHeader_default_instance_;
}  // namespace rpc
static void InitDefaultsRpcHeader_rpcheader_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::rpc::_RpcHeader_default_instance_;
    new (ptr) ::rpc::RpcHeader();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::rpc::RpcHeader::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_RpcHeader_rpcheader_2eproto =
{ {ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsRpcHeader_rpcheader_2eproto}, {} };

void InitDefaults_rpcheader_2eproto() {
  ::google::protobuf::internal::InitSCC(&scc_info_RpcHeader_rpcheader_2eproto.base);
}

::google::protobuf::Metadata file_level_metadata_rpcheader_2eproto[1];
constexpr ::google::protobuf::EnumDescriptor const** file_level_enum_descriptors_rpcheader_2eproto = nullptr;
constexpr ::google::protobuf::ServiceDescriptor const** file_level_service_descriptors_rpcheader_2eproto = nullptr;

const ::google::protobuf::uint32 TableStruct_rpcheader_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::rpc::RpcHeader, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::rpc::RpcHeader, service_name_),
  PROTOBUF_FIELD_OFFSET(::rpc::RpcHeader, method_name_),
  PROTOBUF_FIELD_OFFSET(::rpc::RpcHeader, args_size_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::rpc::RpcHeader)},
};

static ::google::protobuf::Message const* const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::rpc::_RpcHeader_default_instance_),
};

::google::protobuf::internal::AssignDescriptorsTable assign_descriptors_table_rpcheader_2eproto = {
  {}, AddDescriptors_rpcheader_2eproto, "rpcheader.proto", schemas,
  file_default_instances, TableStruct_rpcheader_2eproto::offsets,
  file_level_metadata_rpcheader_2eproto, 1, file_level_enum_descriptors_rpcheader_2eproto, file_level_service_descriptors_rpcheader_2eproto,
};

const char descriptor_table_protodef_rpcheader_2eproto[] =
"\n\017rpcheader.proto\022\003rpc\"I\n\tRpcHeader\022\024\n\014s"
"ervice_name\030\001 \001(\014\022\023\n\013method_name\030\002 \001(\014\022\021"
"\n\targs_size\030\003 \001(\rb\006proto3"
;
::google::protobuf::internal::DescriptorTable descriptor_table_rpcheader_2eproto = {
  false, InitDefaults_rpcheader_2eproto,
  descriptor_table_protodef_rpcheader_2eproto,
  "rpcheader.proto", &assign_descriptors_table_rpcheader_2eproto, 105,
};

void AddDescriptors_rpcheader_2eproto() {
  static constexpr ::google::protobuf::internal::InitFunc deps[1] =
  {
  };
  ::google::protobuf::internal::AddDescriptors(&descriptor_table_rpcheader_2eproto, deps, 0);
}

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_rpcheader_2eproto = []() { AddDescriptors_rpcheader_2eproto(); return true; }();
namespace rpc {

  // ===================================================================

  void RpcHeader::InitAsDefaultInstance() {
  }
  class RpcHeader::HasBitSetters {
  public:
  };

#if !defined(_MSC_VER) || _MSC_VER >= 1900
  const int RpcHeader::kServiceNameFieldNumber;
  const int RpcHeader::kMethodNameFieldNumber;
  const int RpcHeader::kArgsSizeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

  RpcHeader::RpcHeader()
    : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
    SharedCtor();
    // @@protoc_insertion_point(constructor:rpc.RpcHeader)
  }
  RpcHeader::RpcHeader(const RpcHeader& from)
    : ::google::protobuf::Message(),
    _internal_metadata_(nullptr) {
    _internal_metadata_.MergeFrom(from._internal_metadata_);
    service_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    if (from.service_name().size() > 0) {
      service_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.service_name_);
    }
    method_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    if (from.method_name().size() > 0) {
      method_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.method_name_);
    }
    args_size_ = from.args_size_;
    // @@protoc_insertion_point(copy_constructor:rpc.RpcHeader)
  }

  void RpcHeader::SharedCtor() {
    ::google::protobuf::internal::InitSCC(
      &scc_info_RpcHeader_rpcheader_2eproto.base);
    service_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    method_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    args_size_ = 0u;
  }

  RpcHeader::~RpcHeader() {
    // @@protoc_insertion_point(destructor:rpc.RpcHeader)
    SharedDtor();
  }

  void RpcHeader::SharedDtor() {
    service_name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    method_name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }

  void RpcHeader::SetCachedSize(int size) const {
    _cached_size_.Set(size);
  }
  const RpcHeader& RpcHeader::default_instance() {
    ::google::protobuf::internal::InitSCC(&::scc_info_RpcHeader_rpcheader_2eproto.base);
    return *internal_default_instance();
  }


  void RpcHeader::Clear() {
    // @@protoc_insertion_point(message_clear_start:rpc.RpcHeader)
    ::google::protobuf::uint32 cached_has_bits = 0;
    // Prevent compiler warnings about cached_has_bits being unused
    (void)cached_has_bits;

    service_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    method_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    args_size_ = 0u;
    _internal_metadata_.Clear();
  }

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* RpcHeader::_InternalParse(const char* begin, const char* end, void* object,
    ::google::protobuf::internal::ParseContext* ctx) {
    auto msg = static_cast<RpcHeader*>(object);
    ::google::protobuf::int32 size; (void)size;
    int depth; (void)depth;
    ::google::protobuf::uint32 tag;
    ::google::protobuf::internal::ParseFunc parser_till_end; (void)parser_till_end;
    auto ptr = begin;
    while (ptr < end) {
      ptr = ::google::protobuf::io::Parse32(ptr, &tag);
      GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
      switch (tag >> 3) {
        // bytes service_name = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) != 10) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        object = msg->mutable_service_name();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParser;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheck(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
            // bytes method_name = 2;
      case 2: {
        if (static_cast<::google::protobuf::uint8>(tag) != 18) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        object = msg->mutable_method_name();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParser;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheck(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
            // uint32 args_size = 3;
      case 3: {
        if (static_cast<::google::protobuf::uint8>(tag) != 24) goto handle_unusual;
        msg->set_args_size(::google::protobuf::internal::ReadVarint(&ptr));
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        break;
      }
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->EndGroup(tag);
          return ptr;
        }
        auto res = UnknownFieldParse(tag, { _InternalParse, msg },
          ptr, end, msg->_internal_metadata_.mutable_unknown_fields(), ctx);
        ptr = res.first;
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr != nullptr);
        if (res.second) return ptr;
      }
      }  // switch
    }  // while
    return ptr;
  string_till_end:
    static_cast<::std::string*>(object)->clear();
    static_cast<::std::string*>(object)->reserve(size);
    goto len_delim_till_end;
  len_delim_till_end:
    return ctx->StoreAndTailCall(ptr, end, { _InternalParse, msg },
      { parser_till_end, object }, size);
  }
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  bool RpcHeader::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
    ::google::protobuf::uint32 tag;
    // @@protoc_insertion_point(parse_start:rpc.RpcHeader)
    for (;;) {
      ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
      tag = p.first;
      if (!p.second) goto handle_unusual;
      switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
        // bytes service_name = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) == (10 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
            input, this->mutable_service_name()));
        }
        else {
          goto handle_unusual;
        }
        break;
      }

            // bytes method_name = 2;
      case 2: {
        if (static_cast<::google::protobuf::uint8>(tag) == (18 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
            input, this->mutable_method_name()));
        }
        else {
          goto handle_unusual;
        }
        break;
      }

            // uint32 args_size = 3;
      case 3: {
        if (static_cast<::google::protobuf::uint8>(tag) == (24 & 0xFF)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
            ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
              input, &args_size_)));
        }
        else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
      }
    }
  success:
    // @@protoc_insertion_point(parse_success:rpc.RpcHeader)
    return true;
  failure:
    // @@protoc_insertion_point(parse_failure:rpc.RpcHeader)
    return false;
#undef DO_
  }
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

  void RpcHeader::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
    // @@protoc_insertion_point(serialize_start:rpc.RpcHeader)
    ::google::protobuf::uint32 cached_has_bits = 0;
    (void)cached_has_bits;

    // bytes service_name = 1;
    if (this->service_name().size() > 0) {
      ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
        1, this->service_name(), output);
    }

    // bytes method_name = 2;
    if (this->method_name().size() > 0) {
      ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
        2, this->method_name(), output);
    }

    // uint32 args_size = 3;
    if (this->args_size() != 0) {
      ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->args_size(), output);
    }

    if (_internal_metadata_.have_unknown_fields()) {
      ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
    }
    // @@protoc_insertion_point(serialize_end:rpc.RpcHeader)
  }

  ::google::protobuf::uint8* RpcHeader::InternalSerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
    // @@protoc_insertion_point(serialize_to_array_start:rpc.RpcHeader)
    ::google::protobuf::uint32 cached_has_bits = 0;
    (void)cached_has_bits;

    // bytes service_name = 1;
    if (this->service_name().size() > 0) {
      target =
        ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
          1, this->service_name(), target);
    }

    // bytes method_name = 2;
    if (this->method_name().size() > 0) {
      target =
        ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
          2, this->method_name(), target);
    }

    // uint32 args_size = 3;
    if (this->args_size() != 0) {
      target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->args_size(), target);
    }

    if (_internal_metadata_.have_unknown_fields()) {
      target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
    }
    // @@protoc_insertion_point(serialize_to_array_end:rpc.RpcHeader)
    return target;
  }

  size_t RpcHeader::ByteSizeLong() const {
    // @@protoc_insertion_point(message_byte_size_start:rpc.RpcHeader)
    size_t total_size = 0;

    if (_internal_metadata_.have_unknown_fields()) {
      total_size +=
        ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
          _internal_metadata_.unknown_fields());
    }
    ::google::protobuf::uint32 cached_has_bits = 0;
    // Prevent compiler warnings about cached_has_bits being unused
    (void)cached_has_bits;

    // bytes service_name = 1;
    if (this->service_name().size() > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->service_name());
    }

    // bytes method_name = 2;
    if (this->method_name().size() > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->method_name());
    }

    // uint32 args_size = 3;
    if (this->args_size() != 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->args_size());
    }

    int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
    SetCachedSize(cached_size);
    return total_size;
  }

  void RpcHeader::MergeFrom(const ::google::protobuf::Message& from) {
    // @@protoc_insertion_point(generalized_merge_from_start:rpc.RpcHeader)
    GOOGLE_DCHECK_NE(&from, this);
    const RpcHeader* source =
      ::google::protobuf::DynamicCastToGenerated<RpcHeader>(
        &from);
    if (source == nullptr) {
      // @@protoc_insertion_point(generalized_merge_from_cast_fail:rpc.RpcHeader)
      ::google::protobuf::internal::ReflectionOps::Merge(from, this);
    }
    else {
      // @@protoc_insertion_point(generalized_merge_from_cast_success:rpc.RpcHeader)
      MergeFrom(*source);
    }
  }

  void RpcHeader::MergeFrom(const RpcHeader& from) {
    // @@protoc_insertion_point(class_specific_merge_from_start:rpc.RpcHeader)
    GOOGLE_DCHECK_NE(&from, this);
    _internal_metadata_.MergeFrom(from._internal_metadata_);
    ::google::protobuf::uint32 cached_has_bits = 0;
    (void)cached_has_bits;

    if (from.service_name().size() > 0) {

      service_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.service_name_);
    }
    if (from.method_name().size() > 0) {

      method_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.method_name_);
    }
    if (from.args_size() != 0) {
      set_args_size(from.args_size());
    }
  }

  void RpcHeader::CopyFrom(const ::google::protobuf::Message& from) {
    // @@protoc_insertion_point(generalized_copy_from_start:rpc.RpcHeader)
    if (&from == this) return;
    Clear();
    MergeFrom(from);
  }

  void RpcHeader::CopyFrom(const RpcHeader& from) {
    // @@protoc_insertion_point(class_specific_copy_from_start:rpc.RpcHeader)
    if (&from == this) return;
    Clear();
    MergeFrom(from);
  }

  bool RpcHeader::IsInitialized() const {
    return true;
  }

  void RpcHeader::Swap(RpcHeader* other) {
    if (other == this) return;
    InternalSwap(other);
  }
  void RpcHeader::InternalSwap(RpcHeader* other) {
    using std::swap;
    _internal_metadata_.Swap(&other->_internal_metadata_);
    service_name_.Swap(&other->service_name_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
    method_name_.Swap(&other->method_name_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
    swap(args_size_, other->args_size_);
  }

  ::google::protobuf::Metadata RpcHeader::GetMetadata() const {
    ::google::protobuf::internal::AssignDescriptors(&::assign_descriptors_table_rpcheader_2eproto);
    return ::file_level_metadata_rpcheader_2eproto[kIndexInFileMessages];
  }


  // @@protoc_insertion_point(namespace_scope)
}  // namespace rpc
namespace google {
  namespace protobuf {
    template<> PROTOBUF_NOINLINE::rpc::RpcHeader* Arena::CreateMaybeMessage< ::rpc::RpcHeader >(Arena* arena) {
      return Arena::CreateInternal< ::rpc::RpcHeader >(arena);
    }
  }  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
