/*
 * Copyright 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <cstdint>

#include "packets/link_layer/link_layer_packet_view.h"
#include "packets/packet_view.h"

namespace test_vendor_lib {
namespace packets {

class EncryptConnectionView : public PacketView<true> {
 public:
  EncryptConnectionView(const EncryptConnectionView&) = default;
  virtual ~EncryptConnectionView() = default;

  static EncryptConnectionView GetEncryptConnection(const LinkLayerPacketView& view) {
    CHECK(view.GetType() == Link::PacketType::ENCRYPT_CONNECTION ||
          view.GetType() == Link::PacketType::ENCRYPT_CONNECTION_RESPONSE);
    return EncryptConnectionView(view.GetPayload());
  }

  Iterator<true> GetKey() {
    return begin();
  }

 private:
  EncryptConnectionView() = delete;
  EncryptConnectionView(const PacketView<true>& view) : PacketView(view) {}
};

}  // namespace packets
}  // namespace test_vendor_lib
