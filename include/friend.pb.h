// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: friend.proto

#ifndef PROTOBUF_INCLUDED_friend_2eproto
#define PROTOBUF_INCLUDED_friend_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3007000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3007001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_friend_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_friend_2eproto {
  static const ::google::protobuf::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors_friend_2eproto();
namespace fixbug {
  class FriendRequest;
  class FriendRequestDefaultTypeInternal;
  extern FriendRequestDefaultTypeInternal _FriendRequest_default_instance_;
  class FriendResponse;
  class FriendResponseDefaultTypeInternal;
  extern FriendResponseDefaultTypeInternal _FriendResponse_default_instance_;
  class ResultCode1;
  class ResultCode1DefaultTypeInternal;
  extern ResultCode1DefaultTypeInternal _ResultCode1_default_instance_;
}  // namespace fixbug
namespace google {
  namespace protobuf {
    template<> ::fixbug::FriendRequest* Arena::CreateMaybeMessage<::fixbug::FriendRequest>(Arena*);
    template<> ::fixbug::FriendResponse* Arena::CreateMaybeMessage<::fixbug::FriendResponse>(Arena*);
    template<> ::fixbug::ResultCode1* Arena::CreateMaybeMessage<::fixbug::ResultCode1>(Arena*);
  }  // namespace protobuf
}  // namespace google
namespace fixbug {

  // ===================================================================

  class ResultCode1 :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:fixbug.ResultCode1) */ {
  public:
    ResultCode1();
    virtual ~ResultCode1();

    ResultCode1(const ResultCode1& from);

    inline ResultCode1& operator=(const ResultCode1& from) {
      CopyFrom(from);
      return *this;
    }
#if LANG_CXX11
    ResultCode1(ResultCode1&& from) noexcept
      : ResultCode1() {
      *this = ::std::move(from);
    }

    inline ResultCode1& operator=(ResultCode1&& from) noexcept {
      if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
        if (this != &from) InternalSwap(&from);
      }
      else {
        CopyFrom(from);
      }
      return *this;
    }
#endif
    static const ::google::protobuf::Descriptor* descriptor() {
      return default_instance().GetDescriptor();
    }
    static const ResultCode1& default_instance();

    static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
    static inline const ResultCode1* internal_default_instance() {
      return reinterpret_cast<const ResultCode1*>(
        &_ResultCode1_default_instance_);
    }
    static constexpr int kIndexInFileMessages =
      0;

    void Swap(ResultCode1* other);
    friend void swap(ResultCode1& a, ResultCode1& b) {
      a.Swap(&b);
    }

    // implements Message ----------------------------------------------

    inline ResultCode1* New() const final {
      return CreateMaybeMessage<ResultCode1>(nullptr);
    }

    ResultCode1* New(::google::protobuf::Arena* arena) const final {
      return CreateMaybeMessage<ResultCode1>(arena);
    }
    void CopyFrom(const ::google::protobuf::Message& from) final;
    void MergeFrom(const ::google::protobuf::Message& from) final;
    void CopyFrom(const ResultCode1& from);
    void MergeFrom(const ResultCode1& from);
    PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
    bool IsInitialized() const final;

    size_t ByteSizeLong() const final;
#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
    static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
    ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
#else
    bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
    void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
    ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
    int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
    void SharedCtor();
    void SharedDtor();
    void SetCachedSize(int size) const final;
    void InternalSwap(ResultCode1* other);
  private:
    inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
      return nullptr;
    }
    inline void* MaybeArenaPtr() const {
      return nullptr;
    }
  public:

    ::google::protobuf::Metadata GetMetadata() const final;

    // nested types ----------------------------------------------------

    // accessors -------------------------------------------------------

    // bytes errmsg = 2;
    void clear_errmsg();
    static const int kErrmsgFieldNumber = 2;
    const ::std::string& errmsg() const;
    void set_errmsg(const ::std::string& value);
#if LANG_CXX11
    void set_errmsg(::std::string&& value);
#endif
    void set_errmsg(const char* value);
    void set_errmsg(const void* value, size_t size);
    ::std::string* mutable_errmsg();
    ::std::string* release_errmsg();
    void set_allocated_errmsg(::std::string* errmsg);

    // int32 errcode = 1;
    void clear_errcode();
    static const int kErrcodeFieldNumber = 1;
    ::google::protobuf::int32 errcode() const;
    void set_errcode(::google::protobuf::int32 value);

    // @@protoc_insertion_point(class_scope:fixbug.ResultCode1)
  private:
    class HasBitSetters;

    ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
    ::google::protobuf::internal::ArenaStringPtr errmsg_;
    ::google::protobuf::int32 errcode_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    friend struct ::TableStruct_friend_2eproto;
  };
  // -------------------------------------------------------------------

  class FriendRequest :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:fixbug.FriendRequest) */ {
  public:
    FriendRequest();
    virtual ~FriendRequest();

    FriendRequest(const FriendRequest& from);

    inline FriendRequest& operator=(const FriendRequest& from) {
      CopyFrom(from);
      return *this;
    }
#if LANG_CXX11
    FriendRequest(FriendRequest&& from) noexcept
      : FriendRequest() {
      *this = ::std::move(from);
    }

    inline FriendRequest& operator=(FriendRequest&& from) noexcept {
      if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
        if (this != &from) InternalSwap(&from);
      }
      else {
        CopyFrom(from);
      }
      return *this;
    }
#endif
    static const ::google::protobuf::Descriptor* descriptor() {
      return default_instance().GetDescriptor();
    }
    static const FriendRequest& default_instance();

    static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
    static inline const FriendRequest* internal_default_instance() {
      return reinterpret_cast<const FriendRequest*>(
        &_FriendRequest_default_instance_);
    }
    static constexpr int kIndexInFileMessages =
      1;

    void Swap(FriendRequest* other);
    friend void swap(FriendRequest& a, FriendRequest& b) {
      a.Swap(&b);
    }

    // implements Message ----------------------------------------------

    inline FriendRequest* New() const final {
      return CreateMaybeMessage<FriendRequest>(nullptr);
    }

    FriendRequest* New(::google::protobuf::Arena* arena) const final {
      return CreateMaybeMessage<FriendRequest>(arena);
    }
    void CopyFrom(const ::google::protobuf::Message& from) final;
    void MergeFrom(const ::google::protobuf::Message& from) final;
    void CopyFrom(const FriendRequest& from);
    void MergeFrom(const FriendRequest& from);
    PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
    bool IsInitialized() const final;

    size_t ByteSizeLong() const final;
#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
    static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
    ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
#else
    bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
    void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
    ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
    int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
    void SharedCtor();
    void SharedDtor();
    void SetCachedSize(int size) const final;
    void InternalSwap(FriendRequest* other);
  private:
    inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
      return nullptr;
    }
    inline void* MaybeArenaPtr() const {
      return nullptr;
    }
  public:

    ::google::protobuf::Metadata GetMetadata() const final;

    // nested types ----------------------------------------------------

    // accessors -------------------------------------------------------

    // uint32 id = 1;
    void clear_id();
    static const int kIdFieldNumber = 1;
    ::google::protobuf::uint32 id() const;
    void set_id(::google::protobuf::uint32 value);

    // @@protoc_insertion_point(class_scope:fixbug.FriendRequest)
  private:
    class HasBitSetters;

    ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
    ::google::protobuf::uint32 id_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    friend struct ::TableStruct_friend_2eproto;
  };
  // -------------------------------------------------------------------

  class FriendResponse :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:fixbug.FriendResponse) */ {
  public:
    FriendResponse();
    virtual ~FriendResponse();

    FriendResponse(const FriendResponse& from);

    inline FriendResponse& operator=(const FriendResponse& from) {
      CopyFrom(from);
      return *this;
    }
#if LANG_CXX11
    FriendResponse(FriendResponse&& from) noexcept
      : FriendResponse() {
      *this = ::std::move(from);
    }

    inline FriendResponse& operator=(FriendResponse&& from) noexcept {
      if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
        if (this != &from) InternalSwap(&from);
      }
      else {
        CopyFrom(from);
      }
      return *this;
    }
#endif
    static const ::google::protobuf::Descriptor* descriptor() {
      return default_instance().GetDescriptor();
    }
    static const FriendResponse& default_instance();

    static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
    static inline const FriendResponse* internal_default_instance() {
      return reinterpret_cast<const FriendResponse*>(
        &_FriendResponse_default_instance_);
    }
    static constexpr int kIndexInFileMessages =
      2;

    void Swap(FriendResponse* other);
    friend void swap(FriendResponse& a, FriendResponse& b) {
      a.Swap(&b);
    }

    // implements Message ----------------------------------------------

    inline FriendResponse* New() const final {
      return CreateMaybeMessage<FriendResponse>(nullptr);
    }

    FriendResponse* New(::google::protobuf::Arena* arena) const final {
      return CreateMaybeMessage<FriendResponse>(arena);
    }
    void CopyFrom(const ::google::protobuf::Message& from) final;
    void MergeFrom(const ::google::protobuf::Message& from) final;
    void CopyFrom(const FriendResponse& from);
    void MergeFrom(const FriendResponse& from);
    PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
    bool IsInitialized() const final;

    size_t ByteSizeLong() const final;
#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
    static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
    ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
#else
    bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
    void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
    ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
    int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
    void SharedCtor();
    void SharedDtor();
    void SetCachedSize(int size) const final;
    void InternalSwap(FriendResponse* other);
  private:
    inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
      return nullptr;
    }
    inline void* MaybeArenaPtr() const {
      return nullptr;
    }
  public:

    ::google::protobuf::Metadata GetMetadata() const final;

    // nested types ----------------------------------------------------

    // accessors -------------------------------------------------------

    // repeated bytes friends = 2;
    int friends_size() const;
    void clear_friends();
    static const int kFriendsFieldNumber = 2;
    const ::std::string& friends(int index) const;
    ::std::string* mutable_friends(int index);
    void set_friends(int index, const ::std::string& value);
#if LANG_CXX11
    void set_friends(int index, ::std::string&& value);
#endif
    void set_friends(int index, const char* value);
    void set_friends(int index, const void* value, size_t size);
    ::std::string* add_friends();
    void add_friends(const ::std::string& value);
#if LANG_CXX11
    void add_friends(::std::string&& value);
#endif
    void add_friends(const char* value);
    void add_friends(const void* value, size_t size);
    const ::google::protobuf::RepeatedPtrField<::std::string>& friends() const;
    ::google::protobuf::RepeatedPtrField<::std::string>* mutable_friends();

    // .fixbug.ResultCode1 result = 1;
    bool has_result() const;
    void clear_result();
    static const int kResultFieldNumber = 1;
    const ::fixbug::ResultCode1& result() const;
    ::fixbug::ResultCode1* release_result();
    ::fixbug::ResultCode1* mutable_result();
    void set_allocated_result(::fixbug::ResultCode1* result);

    // @@protoc_insertion_point(class_scope:fixbug.FriendResponse)
  private:
    class HasBitSetters;

    ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
    ::google::protobuf::RepeatedPtrField<::std::string> friends_;
    ::fixbug::ResultCode1* result_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    friend struct ::TableStruct_friend_2eproto;
  };
  // ===================================================================

  class FriendServiceRpc_Stub;

  class FriendServiceRpc : public ::google::protobuf::Service {
  protected:
    // This class should be treated as an abstract interface.
    inline FriendServiceRpc() {};
  public:
    virtual ~FriendServiceRpc();

    typedef FriendServiceRpc_Stub Stub;

    static const ::google::protobuf::ServiceDescriptor* descriptor();

    virtual void GetFriendList(::google::protobuf::RpcController* controller,
      const ::fixbug::FriendRequest* request,
      ::fixbug::FriendResponse* response,
      ::google::protobuf::Closure* done);

    // implements Service ----------------------------------------------

    const ::google::protobuf::ServiceDescriptor* GetDescriptor();
    void CallMethod(const ::google::protobuf::MethodDescriptor* method,
      ::google::protobuf::RpcController* controller,
      const ::google::protobuf::Message* request,
      ::google::protobuf::Message* response,
      ::google::protobuf::Closure* done);
    const ::google::protobuf::Message& GetRequestPrototype(
      const ::google::protobuf::MethodDescriptor* method) const;
    const ::google::protobuf::Message& GetResponsePrototype(
      const ::google::protobuf::MethodDescriptor* method) const;

  private:
    GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FriendServiceRpc);
  };

  class FriendServiceRpc_Stub : public FriendServiceRpc {
  public:
    FriendServiceRpc_Stub(::google::protobuf::RpcChannel* channel);
    FriendServiceRpc_Stub(::google::protobuf::RpcChannel* channel,
      ::google::protobuf::Service::ChannelOwnership ownership);
    ~FriendServiceRpc_Stub();

    inline ::google::protobuf::RpcChannel* channel() { return channel_; }

    // implements FriendServiceRpc ------------------------------------------

    void GetFriendList(::google::protobuf::RpcController* controller,
      const ::fixbug::FriendRequest* request,
      ::fixbug::FriendResponse* response,
      ::google::protobuf::Closure* done);
  private:
    ::google::protobuf::RpcChannel* channel_;
    bool owns_channel_;
    GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FriendServiceRpc_Stub);
  };


  // ===================================================================


  // ===================================================================

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ResultCode1

// int32 errcode = 1;
  inline void ResultCode1::clear_errcode() {
    errcode_ = 0;
  }
  inline ::google::protobuf::int32 ResultCode1::errcode() const {
    // @@protoc_insertion_point(field_get:fixbug.ResultCode1.errcode)
    return errcode_;
  }
  inline void ResultCode1::set_errcode(::google::protobuf::int32 value) {

    errcode_ = value;
    // @@protoc_insertion_point(field_set:fixbug.ResultCode1.errcode)
  }

  // bytes errmsg = 2;
  inline void ResultCode1::clear_errmsg() {
    errmsg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  inline const ::std::string& ResultCode1::errmsg() const {
    // @@protoc_insertion_point(field_get:fixbug.ResultCode1.errmsg)
    return errmsg_.GetNoArena();
  }
  inline void ResultCode1::set_errmsg(const ::std::string& value) {

    errmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:fixbug.ResultCode1.errmsg)
  }
#if LANG_CXX11
  inline void ResultCode1::set_errmsg(::std::string&& value) {

    errmsg_.SetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
    // @@protoc_insertion_point(field_set_rvalue:fixbug.ResultCode1.errmsg)
  }
#endif
  inline void ResultCode1::set_errmsg(const char* value) {
    // GOOGLE_DCHECK(value != nullptr);

    errmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:fixbug.ResultCode1.errmsg)
  }
  inline void ResultCode1::set_errmsg(const void* value, size_t size) {

    errmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:fixbug.ResultCode1.errmsg)
  }
  inline ::std::string* ResultCode1::mutable_errmsg() {

    // @@protoc_insertion_point(field_mutable:fixbug.ResultCode1.errmsg)
    return errmsg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  inline ::std::string* ResultCode1::release_errmsg() {
    // @@protoc_insertion_point(field_release:fixbug.ResultCode1.errmsg)

    return errmsg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  inline void ResultCode1::set_allocated_errmsg(::std::string* errmsg) {
    if (errmsg != nullptr) {

    }
    else {

    }
    errmsg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), errmsg);
    // @@protoc_insertion_point(field_set_allocated:fixbug.ResultCode1.errmsg)
  }

  // -------------------------------------------------------------------

  // FriendRequest

  // uint32 id = 1;
  inline void FriendRequest::clear_id() {
    id_ = 0u;
  }
  inline ::google::protobuf::uint32 FriendRequest::id() const {
    // @@protoc_insertion_point(field_get:fixbug.FriendRequest.id)
    return id_;
  }
  inline void FriendRequest::set_id(::google::protobuf::uint32 value) {

    id_ = value;
    // @@protoc_insertion_point(field_set:fixbug.FriendRequest.id)
  }

  // -------------------------------------------------------------------

  // FriendResponse

  // .fixbug.ResultCode1 result = 1;
  inline bool FriendResponse::has_result() const {
    return this != internal_default_instance() && result_ != nullptr;
  }
  inline void FriendResponse::clear_result() {
    if (GetArenaNoVirtual() == nullptr && result_ != nullptr) {
      delete result_;
    }
    result_ = nullptr;
  }
  inline const ::fixbug::ResultCode1& FriendResponse::result() const {
    const ::fixbug::ResultCode1* p = result_;
    // @@protoc_insertion_point(field_get:fixbug.FriendResponse.result)
    return p != nullptr ? *p : *reinterpret_cast<const ::fixbug::ResultCode1*>(
      &::fixbug::_ResultCode1_default_instance_);
  }
  inline ::fixbug::ResultCode1* FriendResponse::release_result() {
    // @@protoc_insertion_point(field_release:fixbug.FriendResponse.result)

    ::fixbug::ResultCode1* temp = result_;
    result_ = nullptr;
    return temp;
  }
  inline ::fixbug::ResultCode1* FriendResponse::mutable_result() {

    if (result_ == nullptr) {
      auto* p = CreateMaybeMessage<::fixbug::ResultCode1>(GetArenaNoVirtual());
      result_ = p;
    }
    // @@protoc_insertion_point(field_mutable:fixbug.FriendResponse.result)
    return result_;
  }
  inline void FriendResponse::set_allocated_result(::fixbug::ResultCode1* result) {
    ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
    if (message_arena == nullptr) {
      delete result_;
    }
    if (result) {
      ::google::protobuf::Arena* submessage_arena = nullptr;
      if (message_arena != submessage_arena) {
        result = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, result, submessage_arena);
      }

    }
    else {

    }
    result_ = result;
    // @@protoc_insertion_point(field_set_allocated:fixbug.FriendResponse.result)
  }

  // repeated bytes friends = 2;
  inline int FriendResponse::friends_size() const {
    return friends_.size();
  }
  inline void FriendResponse::clear_friends() {
    friends_.Clear();
  }
  inline const ::std::string& FriendResponse::friends(int index) const {
    // @@protoc_insertion_point(field_get:fixbug.FriendResponse.friends)
    return friends_.Get(index);
  }
  inline ::std::string* FriendResponse::mutable_friends(int index) {
    // @@protoc_insertion_point(field_mutable:fixbug.FriendResponse.friends)
    return friends_.Mutable(index);
  }
  inline void FriendResponse::set_friends(int index, const ::std::string& value) {
    // @@protoc_insertion_point(field_set:fixbug.FriendResponse.friends)
    friends_.Mutable(index)->assign(value);
  }
#if LANG_CXX11
  inline void FriendResponse::set_friends(int index, ::std::string&& value) {
    // @@protoc_insertion_point(field_set:fixbug.FriendResponse.friends)
    friends_.Mutable(index)->assign(std::move(value));
  }
#endif
  inline void FriendResponse::set_friends(int index, const char* value) {
    // GOOGLE_DCHECK(value != nullptr);
    friends_.Mutable(index)->assign(value);
    // @@protoc_insertion_point(field_set_char:fixbug.FriendResponse.friends)
  }
  inline void FriendResponse::set_friends(int index, const void* value, size_t size) {
    friends_.Mutable(index)->assign(
      reinterpret_cast<const char*>(value), size);
    // @@protoc_insertion_point(field_set_pointer:fixbug.FriendResponse.friends)
  }
  inline ::std::string* FriendResponse::add_friends() {
    // @@protoc_insertion_point(field_add_mutable:fixbug.FriendResponse.friends)
    return friends_.Add();
  }
  inline void FriendResponse::add_friends(const ::std::string& value) {
    friends_.Add()->assign(value);
    // @@protoc_insertion_point(field_add:fixbug.FriendResponse.friends)
  }
#if LANG_CXX11
  inline void FriendResponse::add_friends(::std::string&& value) {
    friends_.Add(std::move(value));
    // @@protoc_insertion_point(field_add:fixbug.FriendResponse.friends)
  }
#endif
  inline void FriendResponse::add_friends(const char* value) {
    // GOOGLE_DCHECK(value != nullptr);
    friends_.Add()->assign(value);
    // @@protoc_insertion_point(field_add_char:fixbug.FriendResponse.friends)
  }
  inline void FriendResponse::add_friends(const void* value, size_t size) {
    friends_.Add()->assign(reinterpret_cast<const char*>(value), size);
    // @@protoc_insertion_point(field_add_pointer:fixbug.FriendResponse.friends)
  }
  inline const ::google::protobuf::RepeatedPtrField<::std::string>&
    FriendResponse::friends() const {
    // @@protoc_insertion_point(field_list:fixbug.FriendResponse.friends)
    return friends_;
  }
  inline ::google::protobuf::RepeatedPtrField<::std::string>*
    FriendResponse::mutable_friends() {
    // @@protoc_insertion_point(field_mutable_list:fixbug.FriendResponse.friends)
    return &friends_;
  }

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__
  // -------------------------------------------------------------------

  // -------------------------------------------------------------------


  // @@protoc_insertion_point(namespace_scope)

}  // namespace fixbug

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_friend_2eproto
