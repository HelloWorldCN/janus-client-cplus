/**
 * This file is part of janus_client project.
 * Author:    Jackie Ou
 * Created:   2020-10-01
 **/

#pragma once

#include <string>
#include "xpack.h"

namespace vi {

	struct JanusRequest {
		std::string janus;
		std::string token;
		std::string apisecret;
		std::string transaction;

		XPACK(O(janus, token, apisecret, transaction));
	};

	struct JanusResponse {
		std::string janus;
		std::string transaction;		
		int64_t session_id = -1;
		int64_t sender = -1;
		XPACK(O(janus, transaction, session_id, sender));
	};

	struct Jsep {
		std::string type;
		std::string sdp;

		XPACK(O(type, sdp));
	};

	struct JanusError {
		int64_t code;
		std::string reason;

		XPACK(O(code), O(reason));
	};

	struct JanusData {
		std::string videoroom;

		XPACK(O(videoroom));
	};

	struct PluginData {
		std::string plugin;
		JanusData data;

		XPACK(O(plugin, data));
	};

	struct ReconnectRequest : public JanusRequest {
		int64_t session_id;

		XPACK(I(JanusRequest), O(session_id));
	};

	struct KeepAliveRequest : public JanusRequest {
		int64_t session_id;

		XPACK(I(JanusRequest), O(session_id));
	};

	struct AttachRequest : public JanusRequest {
		int64_t session_id;
		std::string plugin;
		std::string opaque_id;
		XPACK(I(JanusRequest), O(session_id, plugin, opaque_id));
	};

	struct AttachData {
		int64_t id;
		XPACK(O(id));
	};

	struct AttachResponse : public JanusResponse {
		AttachData data;
		XPACK(I(JanusResponse), O(data));
	};

	struct DetachRequest : public JanusRequest {
		int64_t session_id;
		int64_t handle_id;
		XPACK(I(JanusRequest), O(session_id, handle_id));
	};

	struct HangupRequest : public JanusRequest {
		int64_t session_id;
		int64_t handle_id;
		XPACK(I(JanusRequest), O(session_id, handle_id));
	};

	struct HangupResponse : public JanusResponse {
		std::string reason;
		XPACK(I(JanusResponse), O(reason));
	};

	struct MediaResponse : public JanusResponse {
		std::string type;
		bool receiving;
		XPACK(I(JanusResponse), O(type, receiving));
	};

	struct SlowlinkResponse : public JanusResponse {
		bool uplink;
		bool lost;
		XPACK(I(JanusResponse), O(uplink, lost));
	};

	struct JanusEvent : public JanusResponse {
		PluginData plugindata;
		Jsep jsep;
		XPACK(I(JanusResponse), O(plugindata, jsep));
	};

	struct DestroyRequest : public JanusRequest {
		int64_t session_id;

		XPACK(I(JanusRequest), O(session_id));
	};

	struct CreateSessionData {
		int64_t id;
		XPACK(O(id));
	};

	struct CreateSessionResponse : public JanusResponse {
		CreateSessionData data;
		XPACK(I(JanusResponse), O(data));
	};

	struct CandidateData {
		std::string candidate;
		std::string sdpMid;
		int64_t sdpMLineIndex;
		bool completed;
		XPACK(O(candidate, sdpMid, sdpMLineIndex, completed));
	};

	struct TrickleRequest : public JanusRequest {
		int64_t session_id;
		int64_t handle_id;
		CandidateData candidate;
		XPACK(I(JanusRequest), O(session_id, handle_id, candidate));
	};

	struct TrickleResponse : public JanusResponse {
		CandidateData candidate;
		XPACK(I(JanusResponse), O(candidate));

	};
	struct MessageRequest : public JanusRequest {
		int64_t session_id;
		int64_t handle_id;
		std::string body;
		XPACK(I(JanusRequest), O(session_id, handle_id, body));
	};

	struct JsepRequest : public JanusRequest {
		int64_t session_id;
		int64_t handle_id;
		std::string body;
		std::string jsep;
		XPACK(I(JanusRequest), O(session_id, handle_id, body, jsep));
	};
}