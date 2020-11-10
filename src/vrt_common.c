#include <vrt/vrt_common.h>

#include <stddef.h>

#include "vrt_fixed_point.h"
#include "vrt_util.h"

void vrt_init_header(vrt_header* header) {
    header->packet_type  = VRT_PT_IF_DATA_WITHOUT_STREAM_ID;
    header->has.class_id = false;
    header->has.trailer  = false;
    header->tsm          = false;
    header->tsi          = VRT_TSI_NONE;
    header->tsf          = VRT_TSF_NONE;
    header->packet_count = 0;
    header->packet_size  = 0;
}

void vrt_init_fields(vrt_fields* fields) {
    fields->stream_id                       = 0;
    fields->class_id.oui                    = 0;
    fields->class_id.information_class_code = 0;
    fields->class_id.packet_class_code      = 0;
    fields->integer_seconds_timestamp       = 0;
    fields->fractional_seconds_timestamp    = 0;
}

void vrt_init_trailer(vrt_trailer* trailer) {
    trailer->has.calibrated_time                 = false;
    trailer->has.valid_data                      = false;
    trailer->has.reference_lock                  = false;
    trailer->has.agc_or_mgc                      = false;
    trailer->has.detected_signal                 = false;
    trailer->has.spectral_inversion              = false;
    trailer->has.over_range                      = false;
    trailer->has.sample_loss                     = false;
    trailer->has.user_defined11                  = false;
    trailer->has.user_defined10                  = false;
    trailer->has.user_defined9                   = false;
    trailer->has.user_defined8                   = false;
    trailer->calibrated_time                     = false;
    trailer->valid_data                          = false;
    trailer->reference_lock                      = false;
    trailer->agc_or_mgc                          = false;
    trailer->detected_signal                     = false;
    trailer->spectral_inversion                  = false;
    trailer->over_range                          = false;
    trailer->sample_loss                         = false;
    trailer->user_defined11                      = false;
    trailer->user_defined10                      = false;
    trailer->user_defined9                       = false;
    trailer->user_defined8                       = false;
    trailer->has.associated_context_packet_count = false;
    trailer->associated_context_packet_count     = 0;
}

void vrt_init_context(vrt_context* context) {
    context->context_field_change_indicator     = false;
    context->has.reference_point_identifier     = false;
    context->has.bandwidth                      = false;
    context->has.if_reference_frequency         = false;
    context->has.rf_reference_frequency         = false;
    context->has.rf_reference_frequency_offset  = false;
    context->has.if_band_offset                 = false;
    context->has.reference_level                = false;
    context->has.gain                           = false;
    context->has.over_range_count               = false;
    context->has.sample_rate                    = false;
    context->has.timestamp_adjustment           = false;
    context->has.timestamp_calibration_time     = false;
    context->has.temperature                    = false;
    context->has.device_identifier              = false;
    context->has.state_and_event_indicators     = false;
    context->has.data_packet_payload_format     = false;
    context->has.formatted_gps_geolocation      = false;
    context->has.formatted_ins_geolocation      = false;
    context->has.ecef_ephemeris                 = false;
    context->has.relative_ephemeris             = false;
    context->has.ephemeris_reference_identifier = false;
    context->has.gps_ascii                      = false;
    context->has.context_association_lists      = false;

    context->reference_point_identifier    = 0;
    context->bandwidth                     = 0.0;
    context->if_reference_frequency        = 0.0;
    context->rf_reference_frequency        = 0.0;
    context->rf_reference_frequency_offset = 0.0;
    context->if_band_offset                = 0.0;
    context->reference_level               = 0.0F;
    context->gain.stage1                   = 0.0F;
    context->gain.stage2                   = 0.0F;
    context->over_range_count              = 0;
    context->sample_rate                   = 0.0;
    context->timestamp_adjustment          = 0;
    context->timestamp_calibration_time    = 0;
    context->temperature                   = 0.0F;

    context->device_identifier.oui         = 0;
    context->device_identifier.device_code = 0;

    context->state_and_event_indicators.has.calibrated_time    = false;
    context->state_and_event_indicators.has.valid_data         = false;
    context->state_and_event_indicators.has.reference_lock     = false;
    context->state_and_event_indicators.has.agc_or_mgc         = false;
    context->state_and_event_indicators.has.detected_signal    = false;
    context->state_and_event_indicators.has.spectral_inversion = false;
    context->state_and_event_indicators.has.over_range         = false;
    context->state_and_event_indicators.has.sample_loss        = false;
    context->state_and_event_indicators.calibrated_time        = false;
    context->state_and_event_indicators.valid_data             = false;
    context->state_and_event_indicators.reference_lock         = false;
    context->state_and_event_indicators.agc_or_mgc             = false;
    context->state_and_event_indicators.detected_signal        = false;
    context->state_and_event_indicators.spectral_inversion     = false;
    context->state_and_event_indicators.over_range             = false;
    context->state_and_event_indicators.sample_loss            = false;
    context->state_and_event_indicators.user_defined7          = false;
    context->state_and_event_indicators.user_defined6          = false;
    context->state_and_event_indicators.user_defined5          = false;
    context->state_and_event_indicators.user_defined4          = false;
    context->state_and_event_indicators.user_defined3          = false;
    context->state_and_event_indicators.user_defined2          = false;
    context->state_and_event_indicators.user_defined1          = false;
    context->state_and_event_indicators.user_defined0          = false;

    context->data_packet_payload_format.packing_method          = false;
    context->data_packet_payload_format.real_or_complex         = VRT_ROC_REAL;
    context->data_packet_payload_format.data_item_format        = VRT_DIF_SIGNED_FIXED_POINT;
    context->data_packet_payload_format.sample_component_repeat = false;
    context->data_packet_payload_format.event_tag_size          = 0;
    context->data_packet_payload_format.channel_tag_size        = 0;
    context->data_packet_payload_format.item_packing_field_size = 0;
    context->data_packet_payload_format.data_item_size          = 0;
    context->data_packet_payload_format.repeat_count            = 0;
    context->data_packet_payload_format.vector_size             = 0;

    context->formatted_gps_geolocation.tsi = VRT_TSI_UNDEFINED;
    context->formatted_gps_geolocation.tsf = VRT_TSF_UNDEFINED;
    context->formatted_gps_geolocation.oui = 0;
    /* Rule 7.1.5.19-1: When the TSI or TSF fields are zero the corresponding Timestamp of Position Fix subfield words
     * shall take the value 0xFFFFFFFF. */
    context->formatted_gps_geolocation.integer_second_timestamp    = 0xFFFFFFFF;
    context->formatted_gps_geolocation.fractional_second_timestamp = 0xFFFFFFFFFFFFFFFF;
    /* Rule 7.1.5.19-14: The Latitude, Longitude, Altitude, Speed Over Ground, Heading, Track Angle, and Magnetic
     * Variation subfields shall take the value 0x7FFFFFFF when unspecified. */
    context->formatted_gps_geolocation.latitude           = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->formatted_gps_geolocation.longitude          = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->formatted_gps_geolocation.altitude           = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 5);
    context->formatted_gps_geolocation.speed_over_ground  = vrt_fixed_point_u32_to_double(0x7FFFFFFF, 16);
    context->formatted_gps_geolocation.heading_angle      = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->formatted_gps_geolocation.track_angle        = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->formatted_gps_geolocation.magnetic_variation = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);

    context->formatted_ins_geolocation.tsi = VRT_TSI_UNDEFINED;
    context->formatted_ins_geolocation.tsf = VRT_TSF_UNDEFINED;
    context->formatted_ins_geolocation.oui = 0;
    /* Rule 7.1.5.19-1: When the TSI or TSF fields are zero the corresponding Timestamp of Position Fix subfield words
     * shall take the value 0xFFFFFFFF. */
    context->formatted_ins_geolocation.integer_second_timestamp    = 0xFFFFFFFF;
    context->formatted_ins_geolocation.fractional_second_timestamp = 0xFFFFFFFFFFFFFFFF;
    /* Rule 7.1.5.19-14: The Latitude, Longitude, Altitude, Speed Over Ground, Heading, Track Angle, and Magnetic
     * Variation subfields shall take the value 0x7FFFFFFF when unspecified. */
    context->formatted_ins_geolocation.latitude           = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->formatted_ins_geolocation.longitude          = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->formatted_ins_geolocation.altitude           = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 5);
    context->formatted_ins_geolocation.speed_over_ground  = vrt_fixed_point_u32_to_double(0x7FFFFFFF, 16);
    context->formatted_ins_geolocation.heading_angle      = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->formatted_ins_geolocation.track_angle        = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->formatted_ins_geolocation.magnetic_variation = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);

    context->ecef_ephemeris.tsi = VRT_TSI_UNDEFINED;
    context->ecef_ephemeris.tsf = VRT_TSF_UNDEFINED;
    context->ecef_ephemeris.oui = 0;
    /* Rule 7.1.5.21-4: The TSI, TSF, OUI, and Timestamp of Position Fix fields shall follow the rules of the
     * corresponding Formatted GPS Geolocation fields given in Section 7.1.5.19. */
    /* Clash here between Rule 7.1.5.21-4 and Rule 7.1.5.21-8. Rule 7.1.5.21-4 seems more reasonable. */
    context->ecef_ephemeris.integer_second_timestamp    = 0xFFFFFFFF;
    context->ecef_ephemeris.fractional_second_timestamp = 0xFFFFFFFFFFFFFFFF;
    context->ecef_ephemeris.position_x                  = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 5);
    context->ecef_ephemeris.position_y                  = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 5);
    context->ecef_ephemeris.position_z                  = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 5);
    context->ecef_ephemeris.altitude_alpha              = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->ecef_ephemeris.altitude_beta               = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->ecef_ephemeris.altitude_phi                = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->ecef_ephemeris.velocity_dx                 = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 16);
    context->ecef_ephemeris.velocity_dy                 = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 16);
    context->ecef_ephemeris.velocity_dz                 = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 16);

    context->relative_ephemeris.tsi = VRT_TSI_UNDEFINED;
    context->relative_ephemeris.tsf = VRT_TSF_UNDEFINED;
    context->relative_ephemeris.oui = 0;
    /* Rule 7.1.5.21-4: The TSI, TSF, OUI, and Timestamp of Position Fix fields shall follow the rules of the
     * corresponding Formatted GPS Geolocation fields given in Section 7.1.5.19. */
    /* Clash here between Rule 7.1.5.21-4 and Rule 7.1.5.21-8. Rule 7.1.5.21-4 seems more reasonable. */
    context->relative_ephemeris.integer_second_timestamp    = 0xFFFFFFFF;
    context->relative_ephemeris.fractional_second_timestamp = 0xFFFFFFFFFFFFFFFF;
    context->relative_ephemeris.position_x                  = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 5);
    context->relative_ephemeris.position_y                  = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 5);
    context->relative_ephemeris.position_z                  = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 5);
    context->relative_ephemeris.altitude_alpha              = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->relative_ephemeris.altitude_beta               = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->relative_ephemeris.altitude_phi                = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 22);
    context->relative_ephemeris.velocity_dx                 = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 16);
    context->relative_ephemeris.velocity_dy                 = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 16);
    context->relative_ephemeris.velocity_dz                 = vrt_fixed_point_i32_to_double(0x7FFFFFFF, 16);

    context->ephemeris_reference_identifier = 0;

    context->gps_ascii.oui             = 0;
    context->gps_ascii.number_of_words = 0;
    context->gps_ascii.ascii           = NULL;

    context->context_association_lists.has.asynchronous_channel_tag_list             = false;
    context->context_association_lists.source_list_size                              = 0;
    context->context_association_lists.system_list_size                              = 0;
    context->context_association_lists.vector_component_list_size                    = 0;
    context->context_association_lists.asynchronous_channel_list_size                = 0;
    context->context_association_lists.source_context_association_list               = NULL;
    context->context_association_lists.system_context_association_list               = NULL;
    context->context_association_lists.vector_component_context_association_list     = NULL;
    context->context_association_lists.asynchronous_channel_context_association_list = NULL;
    context->context_association_lists.asynchronous_channel_tag_list                 = NULL;
}

uint32_t vrt_words_fields(const vrt_header* header) {
    uint32_t words = 0;
    if (vrt_has_stream_id(header->packet_type)) {
        words += 1;
    }
    if (header->has.class_id) {
        words += 2;
    }
    if (header->tsi != VRT_TSI_NONE) {
        words += 1;
    }
    if (header->tsf != VRT_TSF_NONE) {
        words += 2;
    }
    return words;
}

uint32_t vrt_words_trailer(const vrt_header* header) {
    /* Context packets cannot have a trailer */
    if (vrt_is_context(header->packet_type)) {
        return 0;
    }
    return vrt_b2u(header->has.trailer);
}

uint32_t vrt_words_context(const vrt_context* context) {
    /* Count non-variable words */
    uint32_t words = vrt_words_context_indicator(&context->has);

    /* Count variable words */
    if (context->has.gps_ascii) {
        words += 2;
        words += context->gps_ascii.number_of_words & 0x00FFFFFFU;
    }
    if (context->has.context_association_lists) {
        const vrt_context_association_lists* cal = &context->context_association_lists;
        const uint16_t                       sz1 = cal->source_list_size & 0x01FFU;
        const uint16_t                       sz2 = cal->system_list_size & 0x01FFU;
        const uint16_t                       sz3 = cal->vector_component_list_size;
        const uint16_t                       sz4 = cal->asynchronous_channel_list_size & 0x7FFFU;

        words += 2;
        words += sz1;
        words += sz2;
        words += sz3;
        if (cal->has.asynchronous_channel_tag_list) {
            words += sz4;
        }
        words += sz4;
    }

    return words;
}

extern bool vrt_is_context(vrt_packet_type type);

extern bool is_platform_little_endian();
